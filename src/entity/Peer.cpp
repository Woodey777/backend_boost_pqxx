#include "Peer.hpp"

Peer::Peer(const nlohmann::json& json) {
  if (json.count("id") != 0) {
    m_id = json.at("id").get<int>();
  }
  json.at("name").get_to(m_name);
  json.at("login").get_to(m_login);
  json.at("xp").get_to(m_xp);
}

std::optional<int> Peer::getId() const {
  return m_id;
}

std::string Peer::getName() const {
  return m_name;
}

std::string Peer::getLogin() const {
  return m_login;
}

unsigned short Peer::getXp() const {
  return m_xp;
}

void Peer::setId(int id) {
  m_id = id;
}

void Peer::setName(std::string name) {
  m_name = name;
}

void Peer::setLogin(std::string login) {
  m_login = login;
}

void Peer::setXp(unsigned short xp) {
  m_xp = xp;
}


void peer_to_json(nlohmann::json& json, const Peer& peer) {
  json = nlohmann::json{
      {"name", peer.getName()}, {"login", peer.getLogin()}, {"xp", peer.getXp()}};
  if (peer.getId().has_value()) {
    json["id"] = peer.getId().value();
  }
}

std::string sql_insert_peer(const Peer& peer) {
  return "INSERT INTO peers (name, login, xp) VALUES ('" + peer.getName()               + "', '" +
                                                           peer.getLogin()              + "', '" +
                                                           std::to_string(peer.getXp()) + "');";
}
