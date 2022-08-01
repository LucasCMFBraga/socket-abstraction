from ctypes import Structure, c_char


class ReadPyVResponse(Structure):
    """Defines the read python version command response payload.
    """
    _pack_ = 1
    _fields_ = [
        ("version", c_char * 64)]
