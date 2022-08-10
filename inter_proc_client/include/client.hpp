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
#include "exception/exceptions.hpp"
#include "interfaces/command_interface.hpp"
#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"


class Client{
    public:
        /**
         * @brief Construct a new Client object
         * 
         * @param ip IP from server to be connect.
         * @param port Server port to be connect.
         */
        Client(std::string ip, std::string port) throw();
        
        /**
         * @brief Construct a new Client object
         * 
         */
        Client() throw();
        
        /**
         * @brief Destroy the Client object
         * 
         */
        ~Client();

        /**
         * @brief send the request with current selected command. 
         * 
         */
        void send_request() throw();
        
        /**
         * @brief accept command to be send for client.
         * 
         * @param command 
         */
        void accept_command(CommandInterface* command);

        /**
         * @brief Establish connection with server.
         * 
         */
        void client_connect() throw();

        /**
         * @brief Finish the connection with server.
         * 
         */
        void client_disconnect() throw();

    private:
        int sockfd;
        addrinfo hints, *client_info;
        CommandInterface* command = nullptr;

        /**
         * @brief Get the server info
         * 
         * @param sa 
         * @return void* 
         */
        void* get_in_addr(struct sockaddr *sa);
};