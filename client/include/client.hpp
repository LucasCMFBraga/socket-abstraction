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
#include "interfaces/command_interface.hpp"
#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"


class Client{
    public:
        int sockfd;
        CommandInterface* command = nullptr;

        /**
         * @brief Construct a new Client object
         * 
         * @param ip IP from server to be connect.
         * @param port Server port to be connect.
         */
        Client(std::string ip, std::string port);
        
        /**
         * @brief Construct a new Client object
         * 
         */
        Client();
        
        /**
         * @brief send the request with current selected command. 
         * 
         */
        void send_request();
        
        /**
         * @brief accept command to be send for client.
         * 
         * @param command 
         */
        void accept_command(CommandInterface* command);

    private:
        char frame[MAXDATASIZE];
        struct addrinfo hints, *client_info;
        int rv;
        char s[INET6_ADDRSTRLEN];

        /**
         * @brief Get the server info
         * 
         * @param sa 
         * @return void* 
         */
        void* get_in_addr(struct sockaddr *sa);
};