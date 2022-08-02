#pragma once

#include <exception>
#include <iostream>
using namespace std;

class ClientExceptionRecv : public exception {
   const char * what () const throw () {
        return "Error during receive message.";
   }
};

class ClientExceptionAddrInfo : public exception {
   const char * what () const throw () {
        return "Error on socket addresses translate.";
   }
};