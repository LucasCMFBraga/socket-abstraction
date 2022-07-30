#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"
#include <iostream>
#include <sys/socket.h>
#include <string.h>

class CommandInterface{
    public:
        Request request;
        Response response;

        virtual Response send_request(int sockfd) = 0;
        friend std::ostream &operator<<(std::ostream &output, const CommandInterface &command);
};