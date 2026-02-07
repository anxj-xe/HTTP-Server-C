#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
int main(){

    int mySocket = socket(AF_INET,SOCK_STREAM,0);
    if(mySocket==-1){
        printf("Socket creation error\n");
        return 1;
    }
    printf("Socket created succesfull\n");

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    int result = bind(mySocket,(struct sockaddr*)&address,sizeof(address));
    printf("Bind to port 8080 successfull\n");

    //Now Listen part

    listen(mySocket,10);

    printf("Socket listening for connection...\n");
    printf("Try http://localhost:8080\n");

    printf("Enter Ctrl+C to stop\n");
    while(1){
        sleep(1);//to wait forever
    }

    return 0;
}