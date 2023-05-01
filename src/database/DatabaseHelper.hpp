#ifndef DATABASE_DATABASEHELPER_HPP
#define DATABASE_DATABASEHELPER_HPP

#include <iostream>
#include <pqxx/pqxx>

#include "../entity/Peer.hpp"

class DatabaseHelper {
 public:
  DatabaseHelper() = default;
  DatabaseHelper(const std::string&   ip, 
                 const unsigned short port,
                 const std::string&   dbName,
                 const std::string&   userName,
                 const std::string&   password);

  int addPeer(const Peer& peer);

 private:
  std::string m_connectionString;

};

#endif  // DATABASE_DATABASEHELPER_HPP