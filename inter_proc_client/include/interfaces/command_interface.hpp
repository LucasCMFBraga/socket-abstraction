#pragma once
#include "entities/request_entity.hpp"
#include "entities/response_entity.hpp"
#include <iostream>
#include <sys/socket.h>
#include <string.h>

/**
 * @brief The abstract class that all command have to implement,
 * to follow the design of architecture the command invoker will use
 * contract of this abstract class.
 */
class CommandInterface{
    public:
        /**
         * @brief Set the response object return by the server
         * 
         * @param Response 
         */
        virtual void set_response(Response Response) = 0;
        /**
         * @brief Get the request object to send to the server.
         * 
         * @return Request 
         */
        virtual Request get_request() = 0;

    protected:
        Request request;
        Response response;
};