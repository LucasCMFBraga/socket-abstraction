#include "commands/py_version_command.hpp"
#include "utils/constants.hpp"
  
PyVersionCommand::PyVersionCommand(){    
    request.command = (uint8_t)OpCode::PY_VERSION;
}

Request PyVersionCommand::get_request(){
    return request;
}

void PyVersionCommand::set_response(Response response){
    this->response = response;
    memmove(&py_version_res, &this->response.payload, sizeof(py_version_res));
}

PyVersionEntityResponse PyVersionCommand::get_response(){
    return py_version_res;
}