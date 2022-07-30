#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

#include "utils/constants.hpp"
#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"

#define PORT "65432" // the port client will be connecting to 
#define IP "127.0.0.1"

class Client{
    public:
        int sockfd, numbytes;
        char frame[MAXDATASIZE];

        struct addrinfo hints, *client_info;
        int rv;
        char s[INET6_ADDRSTRLEN];

        Client(std::string ip, std::string port);
        Client();
        ~Client();
        Response send_request();

    private:
        void* get_in_addr(struct sockaddr *sa);
};