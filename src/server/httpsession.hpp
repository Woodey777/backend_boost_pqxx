#ifndef SERVER_HTTPSESSION_HPP
#define SERVER_HTTPSESSION_HPP

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>
#include <unordered_map>

#include "IAction.hpp"

#include "../action/AddPeerAction.hpp"
#include "../action/JsonExampleAction.hpp"
// #include "../action/ListPersonsAction.hpp"

class HttpSession : public std::enable_shared_from_this<HttpSession> {
 public:
  explicit HttpSession(boost::asio::ip::tcp::socket socket);

  void start();

 private:
  boost::beast::flat_buffer m_buff{8192};
  boost::beast::http::request<boost::beast::http::string_body> m_request;
  boost::beast::http::response<boost::beast::http::dynamic_body> m_response;
  std::unordered_map<std::string, IAction *> m_actions;
  boost::asio::ip::tcp::socket m_socket;

  void doRead();
  void doWrite(std::size_t length);
};

#endif  // SERVER_HTTPSESSION_HPP
