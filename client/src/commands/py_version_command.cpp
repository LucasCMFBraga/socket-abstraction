#include "commands/py_version_command.hpp"

  
Response PyVersionCommand::send_request(int sockfd){    
    request.command = 0x01;
    send(sockfd, &request, sizeof(request), 0);

    if ((recv(sockfd, &response, MAXDATASIZE, 0)) == -1) {
        perror("recv");
        exit(1);
    };

    return response;
}