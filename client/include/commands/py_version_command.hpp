#include "interfaces/command_interface.hpp"
#include "entities/py_version_entity.hpp"


class PyVersionCommand:  public CommandInterface{
    public:
        /**
         * @brief Set the response object
         * 
         * @param response 
         */
        void set_response(Response response);
        
        /**
         * @brief Get the request object
         * 
         * @return Request 
         */
        Request get_request();

        /**
         * @brief Construct a new Py Version Command object
         * 
         */
        PyVersionCommand();
        
        /**
         * @brief Get the response object, so you can acces the response fields.
         * 
         * @return PyVersionEntityResponse 
         */
        PyVersionEntityResponse get_response();

        // operator overloading to print the object
        friend std::ostream &operator<<(std::ostream &output, const PyVersionCommand &command){            
            output <<  "Response status: " <<  (int)command.response.status << std::endl;
            output << "Python Version: " << command.py_version_res.version << std::endl;
        }
    private:
        PyVersionEntityResponse py_version_res;
};