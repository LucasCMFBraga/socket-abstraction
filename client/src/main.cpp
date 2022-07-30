#include "client.hpp"
#include "commands/py_version_command.hpp"

int main(){
    Client client = Client("127.0.0.1","65432");

    PyVersionCommand py_version_command;
    py_version_command.send_request(client.sockfd);

    std::cout << py_version_command;

    return 0;
}