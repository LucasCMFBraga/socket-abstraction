from ctypes import memmove, sizeof, pointer
import sys

from inter_proc_server.request_handler.handler_interface import HandlerInterface
from inter_proc_server.entities.read_py_v import ReadPyVResponse
from inter_proc_server.entities.request import Request
from inter_proc_server.entities.response import Response
from inter_proc_server.entities.response_status import ResponseStatus


class ReadPyVHandler(HandlerInterface):
    def handle(self, request: Request) -> Response:
        """return the current python version

        :param request: no params
        :type request: Request
        :return: return a sucess and the python version.
        :rtype: Response
        """
        py_version = ReadPyVResponse()
        py_version.version = bytes(sys.version, encoding='utf-8')

        response = Response()
        response.status = ResponseStatus.SUCCESS.value
        memmove(response.payload, pointer(py_version), sizeof(py_version))

        return response
