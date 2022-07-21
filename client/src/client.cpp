/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "65432" // the port client will be connecting to 

#define MAXDATASIZE 1024 // max number of bytes we can get at once 
#define PAYLOAD_SIZE 1023

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr,"usage: client hostname\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
            s, sizeof s);
    printf("client: connecting to %s\n", s);

    freeaddrinfo(servinfo); // all done with this structure

    struct Request
    {
        u_int8_t commmand;
        u_int8_t payload[PAYLOAD_SIZE];
    };

    struct Response
    {
        u_int8_t status;
        u_int8_t payload[PAYLOAD_SIZE];
    };

    struct Plot
    {
        int axes_x[127];
        int axes_y[127]; 
    };
    
    struct Plot plot;
    for (int i = 0; i < 256; i++){
        // straight y = ax + b;
        plot.axes_x[i] = i;
        plot.axes_y[i] = i * 2 + 5;
    }

    struct Request m;
    m.commmand = 0x01;
    //memmove(m.payload, &plot, sizeof(plot));

    send(sockfd, &m, sizeof(m), 0);

    if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    struct Response response;
    memmove(&response, buf, sizeof(response));
    response.payload[numbytes] = '\0';
    
    printf("Response status %d\n", response.status);
    printf("client: received '%s'\n",response.payload);
        
        usleep(1000);
    
    close(sockfd);

    return 0;
}