#include "AddPeerAction.hpp"
#include "JsonExampleAction.hpp"
#include "ListPersonsAction.hpp"

Responce AddPeerAction::action(const Request &request) {
    nlohmann::json json;
    Peer peer = Peer(json.parse(request.body));
    DatabaseHelper db("127.0.0.1", 8080, "db", "admin", "admin");
    auto res = db.addPeer(peer);
    return {200, "application/json",
            "{"
            "\"message\": \"Person " +
            peer.getName() + ", " +
            peer.getLogin() + ", " +
            std::to_string(peer.getXp()) +
            " added\""
            "}"};
}

Responce JsonExampleAction::action(const Request &request) {
  return {200, "application/json",
            "{"
            "\"woodey\": \"Nikita\""
            "}"};
}