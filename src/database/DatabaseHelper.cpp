#include "DatabaseHelper.hpp"

DatabaseHelper::DatabaseHelper(const std::string&   ip, 
                               const unsigned short port,
                               const std::string&   dbName,
                               const std::string&   userName,
                               const std::string&   password) 
{
  m_connectionString = "host=" + ip + " port=" + std::to_string(port) + " dbname=" +   dbName + " user=" +     userName + " password=" + password;
}

int DatabaseHelper::addPeer(const Peer& peer) {
  try {
    pqxx::connection dbConnection(m_connectionString.c_str());
    pqxx::work executor(dbConnection);
    executor.exec(sql_insert_peer(peer));
    executor.commit();
    std::cout << "Data was successfully added to db" << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
