#pragma once

#define MAXDATASIZE 1024 // max number of bytes we can get at once 
#define PAYLOAD_SIZE MAXDATASIZE - 1 //max payload size
#define PORT "65432" // the port client will be connecting to 
#define IP "127.0.0.1" // loopback IP

enum class OpCode{
    PY_VERSION = 0x01,
    PLOT = 0x02
};