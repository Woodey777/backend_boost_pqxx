#include "server.hpp"

HttpServer::HttpServer(short port) {
    this->acceptor_(context_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
}

void HttpServer::do_accept() {
    acceptor_.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
        if (!ec) {
            std::make_shared<HttpSession>(std::move(socket))->start();
        }
        do_accept();
    });
}