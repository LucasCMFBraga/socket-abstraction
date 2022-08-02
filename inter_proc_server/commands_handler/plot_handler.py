from matplotlib import pyplot as plt

from inter_proc_server.request_handler.handler_interface import HandlerInterface
from inter_proc_server.entities.plot import PlotRequest
from inter_proc_server.entities.request import Request
from inter_proc_server.entities.response import Response
from inter_proc_server.entities.response_status import ResponseStatus


class PlotHandler(HandlerInterface):
    def handle(self, request: Request) -> Response:
        """Handler to plot matplotlib graph

        :param request: params with axes_y and axes_x
        :type request: Request
        :return: return a success status and any payload.
        :rtype: Response
        """
        plot = PlotRequest.from_buffer(request.payload)

        fig, ax = plt.subplots()
        ax.plot(plot.axes_x, plot.axes_y)

        ax.set(xlabel='Time (ms)', ylabel='Voltage (mV)',
               title='Plot from C++ array')
        ax.grid()

        fig.savefig("plot_from_c_plus.png")
        plt.show()

        response = Response()
        response.status = ResponseStatus.SUCCESS.value

        return response
