from typing import Final
from ctypes import memmove, sizeof, pointer

from inter_proc_server.entities.request import Request
from inter_proc_server.entities.response import Response
from inter_proc_server.entities.response_status import InvalidMessage, ResponseStatus, ErrorMessage

# commands
from inter_proc_server.commands_handler.read_py_v_handler import ReadPyVHandler
from inter_proc_server.commands_handler.plot_handler import PlotHandler


class RequestHandler():
    """Get the incoming request and assign for a handler.
    """
    # the commands implementeds, and the new commands cab be add here.
    __COMMANDS: Final = {
        0x01: ReadPyVHandler(),
        0x02: PlotHandler()
    }

    def handle(self, request: Request) -> Response:
        """ Get thre requests and assign for a request handler.

        :param request: request object with parameters
        :type request: Request
        :return: response object with response values.
        :rtype: Response
        """

        # get command for related the incoming request
        command = self.__COMMANDS.get(request.command, None)

        # if there is not such command return error response.
        if command is None:
            message = InvalidMessage()
            message.error = ErrorMessage.get_message(
                ResponseStatus.INVALID_COMMAND)

            response = Response()
            response.status = ResponseStatus.INVALID_COMMAND.value
            memmove(response.payload, pointer(message), sizeof(message))

            return response

        # else handle the request and return a response
        else:
            return command.handle(request)
