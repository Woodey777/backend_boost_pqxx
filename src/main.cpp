
#include <iostream>
// #include <pqxx/pqxx>
#include <exception>
#include "server/server.hpp"

int main() {
  try {
    HttpServer serv(8080);
    serv.run();
  } catch (std::exception &exc) {
    std::cout << "ERROR: " << exc.what() << std::endl;
  }
}

// int main() {

//   std::string connectionString = "host=0.0.0.0 port=8080 dbname=db user=admin password=admin";

//   try {
//     pqxx::connection connectionObject(connectionString.c_str());

//     pqxx::work executor(connectionObject);

//     pqxx::result res = executor.exec("select * from users");

//     for (auto el : res) {
//         std::cout << "Id: |" << el[0] << " name: |" << el[1] << " age: " << el[2] << std::endl;
//     }

//   } catch (const std::exception& e) {
//     std::cerr << e.what() << std::endl;
//   }

//   return 0;
// }