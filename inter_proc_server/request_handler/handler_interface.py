from abc import ABC, abstractclassmethod
from inter_proc_server.entities.request import Request
from inter_proc_server.entities.response import Response


class HandlerInterface(ABC):
    """
    The handler interface class must be implemented by
    all concret request handlers.
    """
    @abstractclassmethod
    def handle(self, request: Request) -> Response:
        """ Handle the request

        :param request: the request object with params
        :type request: Request
        :return: Response object with response values
        :rtype: Response
        """
        pass