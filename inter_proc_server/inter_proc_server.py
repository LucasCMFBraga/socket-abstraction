import socket
from threading import Thread
from time import sleep

from inter_proc_server.utils.constants import FIRST
from inter_proc_server.request_handler.request_handler import RequestHandler
from inter_proc_server.entities.request import Request
from inter_proc_server.config.config import settings


class InterProcServer:
    """
    The class is responsible for open a socket and get the requisites
    and assign to request handler.

    It is working in the async way, but it can be easily changed to be
    work in the async way.
    """

    def __init__(self) -> None:
        self.__request = []
        self.__response = []
        self.__sock = None
        self.__wait = True
        self.__handler = RequestHandler()

        self.__open_socket()
        self.__call_handler()

    def __del__(self):
        self.__close_socket()

    def __call_handler(self) -> None:
        """
        Call the handler to handle the requests
        """
        while True:
            if self.__request:
                request = self.__request.pop(FIRST)
                response = self.__handler.handle(request)
                self.__response.append(response)
            sleep(0.001)

    def __open_socket(self) -> None:
        """
        Open the socket and start the thread to wait the connection.
        """
        try:
            self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.__sock.bind((settings.IP, settings.PORT))
            self.__sock.listen()

            # start the thread to handle the incoming request
            self.__wait_conn = Thread(
                target=self.__wait_connection, daemon=True)
            self.__wait_conn.start()

        except:
            self.__close_socket()

    def __close_socket(self) -> None:
        """
        Join the thread to kill and close the socket
        """
        self.__wait = False
        self.__wait_conn.join()
        self.__sock.close()

    def __wait_connection(self) -> None:
        """
        Wait for a connection and call the handler
        """
        while self.__wait:
            print("Wating Connection")
            self.__conn, self.__addr = self.__sock.accept()
            self.__handle_request()

    def __handle_request(self):
        """
        Get socket requester and push the request in the queue 
        and wait the response.
        """
        with self.__conn:
            print(f"Connected by {self.__addr}")

            while self.__wait:
                data = self.__conn.recv(settings.MESSAGE_SIZE)
                if data:

                    # add the padding in the message to cast the message structure
                    data += bytearray(settings.MESSAGE_SIZE - len(data))
                    message = Request.from_buffer(bytearray(data))
                    self.__request.append(message)

                    while not self.__response:
                        sleep(0.001)

                    response = self.__response.pop(FIRST)
                    self.__conn.sendall(bytearray(response))

                else:
                    break
