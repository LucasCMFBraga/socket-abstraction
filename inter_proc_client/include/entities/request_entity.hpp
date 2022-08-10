#pragma once

#include <stdint.h>
#include "utils/constants.hpp"

struct Request
{
    uint8_t command;
    uint8_t payload[PAYLOAD_SIZE];
};