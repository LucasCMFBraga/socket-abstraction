from ctypes import Structure, c_char
from enum import Enum


class ResponseStatus(Enum):
    """Defines the error codes.
    """
    SUCCESS = 0
    INVALID_COMMAND = 1
    BUSY = 2


class ErrorMessage:
    """Defines the error messages.
    """
    MESSAGES = {
        ResponseStatus.INVALID_COMMAND: b'Invalid command',
        ResponseStatus.BUSY: b'The server is busy'
    }

    @classmethod
    def get_message(cls, status: ResponseStatus) -> str:
        """Solves a error code for a error message.

        :param status: error code
        :type status: ResponseStatus
        :return: error message
        :rtype: str
        """
        return ErrorMessage.MESSAGES.get(status, "")


class InvalidMessage(Structure):
    """Defines response status.
    """
    _pack_ = 1
    _fields_ = [
        ("error", c_char * 64)]
