from ctypes import Structure, c_uint8

from inter_proc_server.config.config import settings


class Response(Structure):
    """Defines the response frame.
    """
    _pack_ = 1
    _fields_ = [
        ("status", c_uint8),
        ("payload", c_uint8 * (settings.MESSAGE_SIZE -1))]