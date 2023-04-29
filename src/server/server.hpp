#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

#include "HttpSession.hpp"

class HttpServer {
 private:
  boost::asio::io_context m_context;
  boost::asio::ip::tcp::acceptor m_acceptor;

  void doAccept();

 public:
  explicit HttpServer(short port);

  void run();
};

#endif  // SERVER_SERVER_HPP