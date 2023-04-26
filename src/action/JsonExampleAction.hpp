#ifndef ACTION_JSONEXAMPLEACTION_HPP
#define ACTION_JSONEXAMPLEACTION_HPP

#include "../server/iAction.hpp"

class JsonExampleAction : public IAction {
public:

    Responce action(const Request &request) override {
        return {
            200,
            "application/json",
            "{"
            "\"woodey\": \"Nikita\""
            "}"
        };
    }

};

#endif  // ACTION_JSONEXAMPLEACTION_HPP
