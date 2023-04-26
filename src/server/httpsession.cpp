#include "httpsession.hpp"

namespace beast = boost::beast;
namespace asio = boost::asio;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

HttpSession::HttpSession(tcp::socket socket) : socket_(std::move(socket)) {
    actions_["/"] = new JsonExampleAction();
    // actions_["/persons"] = new ListPersonsAction();
    // actions_["/add_person"] = new AddPersonAction();
}

void HttpSession::start() {
    do_read();
}

void HttpSession::do_read() {
    auto self(shared_from_this());
    http::async_read(socket_, buff_, request_, [this, self](boost::system::error_code err, std::size_t len) {
        auto target = request_.target();
        std::cout << "target " << target << std::endl;
        auto pos = target.find('?', 0);
        auto f_target = target.substr(0, pos);
        if (actions_.count(f_target) != 0) {
            std::string body = "";
            auto t = actions_[f_target]->action({target.data(), request_.body()});
            response_.result(t.status);
            response_.set(http::field::content_type, t.content_type);
            beast::ostream(response_.body()) << t.body;
            std::cout << "Result [" << t.status << "] " << t.body << std::endl;
        } else {
            response_.result(http::status::not_found);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body()) << "404 Not Found\r\t";
            std::cout << "Result [404] Not Found" << std::endl;
        }
        response_.content_length(response_.body().size());
        do_write(len);
    });
}

void HttpSession::do_write(std::size_t length) {
    auto self(shared_from_this());
    http::async_write(socket_, response_, [this, self](boost::system::error_code err, std::size_t len) {
        if (!err) {
            request_.clear();
            response_.body().clear();
            buff_.clear();
        }
    });
}