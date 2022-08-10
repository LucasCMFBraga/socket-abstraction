#include "interfaces/command_interface.hpp"
#include "entities/plot_entity.hpp"

class PlotCommand: public CommandInterface{
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
         * @brief Construct a new Plot Command object
         * 
         * @param axes_x x coordinates
         * @param axes_y y coordinates
         */
        PlotCommand(int32_t* axes_x, int32_t* axes_y);
        
        // operator overloading to print the object
        friend std::ostream &operator<<(std::ostream &output, const PlotCommand &command){            
            output <<  "Response status: " <<  (int)command.response.status << std::endl;
            return output;
        }
    private:
        PlotEntityRequest plot_entity;
};
