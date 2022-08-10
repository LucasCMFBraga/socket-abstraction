#pragma once

#include <exception>
#include <iostream>
using namespace std;

class ClientRecvException : public exception {
   const char * what () const throw () {
        return "Error during receive message.";
   }
};

class ClientAddrInfoException : public exception {
   const char * what () const throw () {
        return "Error on socket addresses translate.";
   }
};

class ClientConnectionException : public exception {
   const char * what () const throw () {
        return "Error during the connection.";
   }
};

class ClientDisconnectionException : public exception {
   const char * what () const throw () {
        return "Error during the disconnection.";
   }
};