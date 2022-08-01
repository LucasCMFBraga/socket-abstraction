#pragma once

#include <stdint.h>
#include "utils/constants.hpp"


/**
 * @brief 
 * 
 */
struct Request
{
    uint8_t command;
    uint8_t payload[PAYLOAD_SIZE];
};