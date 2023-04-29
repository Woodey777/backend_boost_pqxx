#include "Server.hpp"

HttpServer::HttpServer(short port)
    : m_acceptor(m_context, boost::asio::ip::tcp::endpoint(
                                boost::asio::ip::tcp::v4(), port)) {}

void HttpServer::doAccept() {
  m_acceptor.async_accept([this](boost::system::error_code ec,
                                 boost::asio::ip::tcp::socket socket) {
    if (!ec) {
      std::make_shared<HttpSession>(std::move(socket))->start();
    }
    doAccept();
  });
}

void HttpServer::run() {
  std::cout << "Start server" << std::endl;
  doAccept();
  m_context.run();
}