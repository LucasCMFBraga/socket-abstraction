#include <stdint.h>
#include "utils/constants.hpp"

#ifndef REQUEST
#define REQUEST 

struct Request
{
    uint8_t command;
    uint8_t payload[PAYLOAD_SIZE];
};

#endif