#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include"sys/socket.h"
#include<netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    //interpret the error number and outputs the error by
    //stderr method
    exit(1);
    //if there is an error exit the program

}
//argc = no of parameters to be passed
//argv = actual parameters
//here argc = 2
// argv = filename and port number
int main(int argc , char *argv[])
{
    if(argc < 2)
    {
        //if port number is not provided
        fprintf(stderr,"port number is not provided . Program is terminated\n");
        exit(1);
    }

    int sockfd,newsockfd,port,n;

    struct sockaddr_in serv_addr,cli_addr;
    //sockaddr_in is in netinet/in.h
    //gives us internet address
    socklen_t clilen;
    //socklen is a datatype in socket.h 
    //a 32 bit datatype

    //creation of socket

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd < 0)
    {
        error("ERROR opening socket .");
    }

    //bzero() clears all data in which it is referenced

    bzero((char *)&serv_addr,sizeof(serv_addr));

    //getting the port number
    port = argv(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    //htons = host to network short 

    //binding the socket

    if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
        error("Binding failed");
    else
        fprintf("binding successful");


}