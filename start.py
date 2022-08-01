"""
Starts the server, and it can be kill with ctrl+C.
"""

import sys
from inter_proc_server.inter_proc_server import InterProcServer

try:
    InterProcServer()
    
except KeyboardInterrupt:
    sys.exit()
