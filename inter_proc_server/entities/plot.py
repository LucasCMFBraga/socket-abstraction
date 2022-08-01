from ctypes import Structure, c_int, c_int32

    
class PlotRequest(Structure):
    """ Defines the plot command request payload.
    """
    _pack_ = 1
    _fields_ = [
        ("axes_x", c_int32 * 127),
        ("axes_y", c_int32 * 127)]