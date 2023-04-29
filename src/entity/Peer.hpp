#ifndef ENTITY_PEER_HPP
#define ENTITY_PEER_HPP

#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <iostream>

class Peer {

public:
  explicit Peer() = default;
  explicit Peer(const nlohmann::json& json);

  std::optional<int> getId() const;
  std::string getName() const;
  std::string getLogin() const;
  unsigned short getXp() const;

  void setId(int id);
  void setName(std::string name);
  void setLogin(std::string login);
  void setXp(unsigned short xp);

private:
  std::optional<int> m_id;
  std::string m_name;
  std::string m_login;
  unsigned short m_xp;
};

void peer_to_json(nlohmann::json& json, const Peer& peer);

std::string sql_insert_peer(const Peer& peer);

#endif  // ENTITY_PEER_HPP