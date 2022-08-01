#pragma once
#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"
#include <iostream>
#include <sys/socket.h>
#include <string.h>

class CommandInterface{
    public:
        virtual void set_response(Response Response) = 0;
        virtual Request get_request() = 0;

    protected:
        Request request;
        Response response;
};