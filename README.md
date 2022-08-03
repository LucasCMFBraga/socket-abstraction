# Abstraction for socket communication.

The abstraction provides a easy way to create commands for communication between server and client, so you have to create the same command in the both sides, client and sever. It was used the design pattern command to facilitate the adding of new commands or change the message sender  "invoker".  

It was developed with different programing language to show the other possibilities for this template. The main point here is the concepts of abstraction, where you can easily add new command, without changes a lot the code and architecture.

- Can be use for inter process communication.
- Can be use for communication between two different devices, take care about *endianness* architecture.
- Can be use to make a bind between different programming languages, as show the code you can use the resource of python using the C++. It able to use the famous python library in c++.

## How to use
```
# to install the dependencies
pip3 install -r requirements.txt
```
```
// to compile the code
make
```

```
# starting the server
python3 start.py
```

```
// And running the client.
./main.o
```

## Add a new commands

- To implement a new command you have to declare the command in both side, client and server. There are two example implemented.

## Enjoy



