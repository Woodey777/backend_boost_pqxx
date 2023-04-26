#ifndef SERVER_IACTION_HPP
#define SERVER_IACTION_HPP

#include <string>

struct Request {
    std::string target;
    std::string body;
};

struct Responce {
    unsigned short status;
    std::string content_type;
    std::string body;
};

class IAction {
public:
    virtual Responce action(const Request &request) = 0;
    virtual ~IAction() {};
};

#endif  // SERVER_IACTION_HPP
