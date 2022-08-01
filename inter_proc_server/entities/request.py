from ctypes import Structure, c_uint8

from inter_proc_server.config.config import settings


class Request(Structure):
    """Defines the request frame.
    """
    _pack_ = 1
    _fields_ = [
        ("command", c_uint8),
        ("payload", c_uint8 * (settings.MESSAGE_SIZE - 1))]
