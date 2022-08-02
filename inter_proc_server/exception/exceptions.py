from typing import Final

class ServerBaseException(Exception):
    pass

class ExceptionMessage:
    server_busy: Final = "Server already in use"

class ServerBusy(ServerBaseException):
    def __init__(self) -> None:
        super().__init__(ExceptionMessage.server_busy)
