#include "interfaces/command_interface.hpp"
#include "entities/py_version_entity.hpp"


class PyVersionCommand:  public CommandInterface{
    public:
        Response send_request(int sockfd);

        friend std::ostream &operator<<(std::ostream &output, const CommandInterface &command){            
            PyVersionEntityResponse py_version_res;
            memset(&py_version_res, '\0', sizeof(py_version_res));
            memmove(&py_version_res, &command.response.payload, sizeof(py_version_res));

            output <<  "Response status: " <<  (int)command.response.status << std::endl;
            output << "Python Version: " << py_version_res.version << std::endl;
        }
};