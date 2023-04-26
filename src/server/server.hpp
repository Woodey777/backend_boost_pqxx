#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include "httpsession.hpp"

class HttpServer {
private:
    boost::asio::io_context context_;
    boost::asio::ip::tcp::acceptor acceptor_;

    void do_accept();

public:
    explicit HttpServer(short port);

    void run();
};


#endif  // SERVER_SERVER_HPP