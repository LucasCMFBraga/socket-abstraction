#include "interfaces/command_interface.hpp"
#include "entities/py_version_entity.hpp"


class PyVersionCommand:  public CommandInterface{
    public:
        void set_response(Response response);
        Request get_request();

        PyVersionCommand();
        PyVersionEntityResponse get_response();

        /**
         * @brief 
         * 
         * @param output 
         * @param command 
         * @return std::ostream& 
         */
        friend std::ostream &operator<<(std::ostream &output, const PyVersionCommand &command){            
            output <<  "Response status: " <<  (int)command.response.status << std::endl;
            output << "Python Version: " << command.py_version_res.version << std::endl;
        }
    private:
        PyVersionEntityResponse py_version_res;
};