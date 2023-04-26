#ifndef SERVER_HTTPSESSION_HPP
#define SERVER_HTTPSESSION_HPP

#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <unordered_map>
#include "iAction.hpp"
#include "../action/AddPersonAction.hpp"
#include "../action/JsonExampleAction.hpp"
#include "../action/ListPersonsAction.hpp"

class HttpSession :
    public std::enable_shared_from_this<HttpSession> {

public:
    explicit HttpSession(boost::asio::ip::tcp::socket socket);

    void start();
private:
    boost::beast::flat_buffer buff_{8192};
    boost::beast::http::request<boost::beast::http::string_body> request_;
    boost::beast::http::response<boost::beast::http::dynamic_body> response_;
    std::unordered_map<std::string, IAction *> actions_;
    boost::asio::ip::tcp::socket socket_;

    void do_read();
    void do_write(std::size_t length);
};

#endif  // SERVER_HTTPSESSION_HPP
