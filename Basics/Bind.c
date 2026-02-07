#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){

    int mySocket = socket(AF_INET,SOCK_STREAM,0);
    if(mySocket==-1){
        printf("Error creating socket!\n");
        return 1;
    }
    printf("Socket created. ID: %d\n",mySocket);

    //Creating a Bind for this socket

    //First we have to make a address

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    int result = bind(mySocket,(struct sockaddr*)&address,sizeof(address));

    printf("Bind created for socket\n");

 