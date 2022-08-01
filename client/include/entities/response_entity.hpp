#pragma once

#include <stdint.h>
#include "utils/constants.hpp"


/**
 * @brief 
 * 
 */
struct Response
{
    uint8_t status;
    uint8_t payload[PAYLOAD_SIZE];
};
