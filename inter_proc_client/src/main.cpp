#include "client.hpp"
#include "commands/py_version_command.hpp"
#include "commands/plot_command.hpp"

int main(){
    // creating coordinate to be plot. 
    int32_t axes_x[127];
    int32_t axes_y[127];

    for (int i = 0; i < 256; i++){
        // straight y = ax + b;
        axes_x[i] = i;
        axes_y[i] = i * 2 + 5;
    }

    // create the client.
    Client* client;
    try{
        client = new Client("127.0.0.1", "65432");
        client->client_connect();
    
    }catch (exception& e){
        cout << e.what() << endl;
    }

    try{
        // plot command request
        PlotCommand plot = PlotCommand(axes_x, axes_y);
        client->accept_command(&plot);
        client->send_request();
        std::cout << plot;
    
    }catch(exception &e){
        cout << e.what() << endl;
    }

    try{
        // python version command request
        PyVersionCommand version;
        client->accept_command(&version);
        client->send_request();
        std::cout << version;

    }catch(exception &e){
        cout << e.what() << endl;
    }

    client->client_disconnect();
    delete client;
    return 0;
}