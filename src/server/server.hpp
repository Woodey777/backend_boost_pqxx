#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <boost/asio.hpp>

class HttpServer {
private:
    boost::asio::io_context context_;
    boost::asio::ip::tcp::acceptor acceptor_;

    void do_accept();

public:
    explicit HttpServer(short port);

    void run();
};


#endif