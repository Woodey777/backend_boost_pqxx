#include "DatabaseHelper.hpp"

DatabaseHelper::DatabaseHelper(const std::string&   ip, 
                               const unsigned short port,
                               const std::string&   dbName,
                               const std::string&   userName,
                               const std::string&   password) 
{
  try {
    // std::string connectionString = "host=" + ip + " port=" + std::to_string(port) + " dbname=" +   dbName + " user=" +     userName + " password=" + password;
    std::cout << "host=" + ip + " port=" + std::to_string(port) + " dbname=" +   dbName + " user=" +     userName + " password=" + password << std::endl;
    // m_dbConnection = pqxx::connection(connectionString.c_str());
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

// int main() {

//   std::string connectionString = "host=0.0.0.0 port=8080 dbname=db user=admin password=admin";

//   try {
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

//   return 0;
// }

int DatabaseHelper::performQuery(std::string query) {
  try {
    pqxx::work executor(m_dbConnection);
    executor.exec(query);
    executor.commit();
    std::cout << "Data was successfully added to db" << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
