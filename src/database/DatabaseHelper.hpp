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

  int performQuery(std::string query);

 private:
  pqxx::connection m_dbConnection;

};

#endif  // DATABASE_DATABASEHELPER_HPP

//   std::string connectionString = "host=0.0.0.0 port=8080 dbname=db user=admin
//   password=admin"; try {
//     pqxx::connection connectionObject(connectionString.c_str());
//     pqxx::work executor(connectionObject);
//     pqxx::result res = executor.exec("select * from users");
//     for (auto el : res) {
//         std::cout << "Id: |" << el[0] << " name: |" << el[1] << " age: " <<
//         el[2] << std::endl;
//     }
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << std::endl;
//   }