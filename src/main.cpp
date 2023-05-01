
#include <iostream>
// #include <pqxx/pqxx>
#include <boost/beast.hpp>
#include <exception>

#include "server/Server.hpp"

int main() {
  try {
    HttpServer serv(1234);
    serv.run();
  } catch (std::exception &exc) {
    std::cout << "ERROR: " << exc.what() << std::endl;
  }
}
