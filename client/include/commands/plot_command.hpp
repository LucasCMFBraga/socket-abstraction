#include "interfaces/command_interface.hpp"
#include "entities/plot_entity.hpp"

class PlotCommand: public CommandInterface{
    public:
        void set_response(Response response);
        Request get_request();

        PlotCommand(int32_t axes_x[127], int32_t axes_y[127]);
        
        friend std::ostream &operator<<(std::ostream &output, const PlotCommand &command){            
            output <<  "Response status: " <<  (int)command.response.status << std::endl;
        }
    private:
        PlotEntityRequest plot_entity;
};
