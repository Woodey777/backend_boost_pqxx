#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

std::string make_time() {
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

using namespace boost::asio;

int main() {
    try {
        boost::asio::io_context context;
        boost::asio::ip::tcp::acceptor acceptor(context, ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 13));
        while (true) {
            boost::asio::ip::tcp::socket socket(context);
            acceptor.accept(socket);
            auto message = make_time();
            std::cout << 'a' << std::endl;
            boost::system::error_code error;
            boost::asio::write(socket, boost::asio::buffer(message), error);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}