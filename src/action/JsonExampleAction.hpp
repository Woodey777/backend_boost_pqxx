#ifndef ACTION_JSONEXAMPLEACTION_HPP
#define ACTION_JSONEXAMPLEACTION_HPP

#include "../server/IAction.hpp"

class JsonExampleAction : public IAction {
 public:
  Responce action(const Request &request) override;
};

#endif  // ACTION_JSONEXAMPLEACTION_HPP
