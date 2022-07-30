#include <stdint.h>
#include "utils/constants.hpp"

#ifndef RESPONSE
#define RESPONSE

struct Response
{
    uint8_t status;
    uint8_t payload[PAYLOAD_SIZE];
};

#endif
