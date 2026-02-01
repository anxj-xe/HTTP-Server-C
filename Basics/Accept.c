#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main(){

    int mySocket = socket(AF_INET,SOCK_STREAM,0);
    if(mySocket==-1){
        printf("Error creating a socket!\n");
        return 1;
    }
    printf("Socket created!\n");

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    int myBind = bind(mySocket,(struct sockaddr*)&address,sizeof(address));
    if(myBind==-1){
        printf("Bind of socket failed!\n");
        return 1;
    }
    printf("Bind of socket successfull\n");

    listen(mySocket,10);
    printf("Listening to port 8080...\n");

    int myAccept = accept(mySocket,NULL,NULL);
    char* massege = "HTTP/1.1 200 OK\r\n\r\nHello from my server!\n";
    char* errormas = "HTTP/1.1 200 OK\r\n\r\n400 not found!\n";
    if(myAccept==-1){
        write(myAccept,errormas,strlen(errormas));
        return 1;
    }

    write(myAccept,massege,strlen(massege));
    close(myAccept);

    return 0;
}