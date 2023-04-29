#ifndef ACTION_ADDPEERACTION_HPP
#define ACTION_ADDPEERACTION_HPP

#include "../database/DatabaseHelper.hpp"
#include "../entity/Peer.hpp"
#include "../server/IAction.hpp"
#include "nlohmann/json.hpp"

class AddPeerAction : public IAction {
public:
  Responce action(const Request &request) override;
};

#endif  // ACTION_ADDPEERACTION_HPP
