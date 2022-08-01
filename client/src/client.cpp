#include "client.hpp"


Client::Client(std::string ip, std::string port){    
    // 
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(ip.c_str(), port.c_str(), &hints, &client_info)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    }

    sockfd = socket(
        client_info->ai_family,
        client_info->ai_socktype,
        client_info->ai_protocol);

    connect(
        sockfd,
        client_info->ai_addr,
        client_info->ai_addrlen);
}

Client::Client(){
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(IP, PORT, &hints, &client_info)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    }

    sockfd = socket(
        client_info->ai_family,
        client_info->ai_socktype,
        client_info->ai_protocol);

    connect(
        sockfd,
        client_info->ai_addr,
        client_info->ai_addrlen);

}

Client::~Client(){
    close(sockfd);
}

void* Client::get_in_addr(struct sockaddr *server_addr){
    if (server_addr->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)server_addr)->sin_addr);
    }
    return &(((struct sockaddr_in6*)server_addr)->sin6_addr);
}

void Client::send_request(){
    if(command != nullptr){
        Request request = command->get_request();
        Response response;

        send(sockfd, &request, sizeof(request), 0);

        if ((recv(sockfd, &response, MAXDATASIZE, 0)) == -1) {
            perror("recv");
            exit(1);
        };
        command->set_response(response);

    }else{
        std::cout << "Assigned no command" << std::endl;
    }
}

void Client::accept_command(CommandInterface* command){
    this->command = command;
}

  