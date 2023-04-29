#include "HttpSession.hpp"

namespace beast = boost::beast;
namespace asio = boost::asio;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

HttpSession::HttpSession(tcp::socket socket) : m_socket(std::move(socket)) {
  m_actions["/"] = new JsonExampleAction();
//   m_actions["/persons"] = new ListPersonsAction();
  m_actions["/add_person"] = new AddPeerAction();
}

void HttpSession::start() { doRead(); }

void HttpSession::doRead() {
  auto self(shared_from_this());
  http::async_read(
      m_socket, m_buff, m_request,
      [this, self](boost::system::error_code err, std::size_t len) {
        auto target = m_request.target();
        std::cout << "target " << target << std::endl;
        auto pos = target.find('?', 0);
        auto f_target = target.substr(0, pos);
        if (m_actions.count(f_target.to_string()) != 0) {
          std::string body = "";
          auto t = m_actions[f_target.to_string()]->action({target.data(), m_request.body()});
          m_response.result(t.status);
          m_response.set(http::field::content_type, t.content_type);
          beast::ostream(m_response.body()) << t.body;
          std::cout << "Result [" << t.status << "] " << t.body << std::endl;
        } else {
          m_response.result(http::status::not_found);
          m_response.set(http::field::content_type, "text/plain");
          beast::ostream(m_response.body()) << "404 Not Found\r\t";
          std::cout << "Result [404] Not Found" << std::endl;
        }
        m_response.content_length(m_response.body().size());
        doWrite(len);
      });
}

void HttpSession::doWrite(std::size_t length) {
  auto self(shared_from_this());
  http::async_write(
      m_socket, m_response,
      [this, self](boost::system::error_code err, std::size_t len) {
        if (!err) {
          m_request.clear();
          m_response.body().clear();
          m_buff.clear();
        }
      });
}