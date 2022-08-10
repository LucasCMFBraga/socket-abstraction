#include "commands/plot_command.hpp"
#include "utils/constants.hpp"

PlotCommand::PlotCommand(int32_t* axes_x, int32_t* axes_y){
    request.command = (uint8_t)OpCode::PLOT;

    // copy the values axes values for entity
    memmove(&plot_entity.axes_x, axes_x, sizeof(plot_entity.axes_x));
    memmove(&plot_entity.axes_y, axes_y, sizeof(plot_entity.axes_x));

    // copy plot entity to request buffer.
    memmove(&request.payload, &plot_entity, sizeof(request.payload));
}

Request PlotCommand::get_request(){
    return request;
}

void PlotCommand::set_response(Response response){
    this->response = response;
}
