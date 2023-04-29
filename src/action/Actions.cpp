#include "AddPeerAction.hpp"
#include "JsonExampleAction.hpp"
#include "ListPersonsAction.hpp"

Responce AddPeerAction::action(const Request &request) {
    nlohmann::json json;
    Peer peer = Peer(json.parse(request.body));
//  "host=0.0.0.0 port=8080 dbname=db user=admin password=admin
    // DatabaseHelper db("0.0.0.0", 8080, "db", "admin", "admin");
    // auto res = db.performQuery(sql_insert_peer(peer));
    // peer.id = res.inserted_oid();
    return {200, "application/json",
            "{"
            "\"message\": \"Person " + peer.getName() +
            " added\""
            "}"};
}

Responce JsonExampleAction::action(const Request &request) {
  return {200, "application/json",
            "{"
            "\"woodey\": \"Nikita\""
            "}"};
}