#include<stdio.h>
#include<sys/socket.h>
int main(){

    //Creating a Socket
    int mySocket = socket(AF_INET,SOCK_STREAM,0);

    /*FOR REVISION
    
    socket(AF_INET, SOCK_STREAM, 0);
       │        │            │
       │        │            └─ Protocol (0 = auto-choose TCP)
       │        └─ Type: SOCK_STREAM = reliable/TCP
       └─ Address Family: AF_INET = IPv4 internet addresses
    */

    if(mySocket==-1){
        printf("Failed to creat a socket!");
        return 1;
    }

    printf("Socket created. ID: %d\n",mySocket);

    return 0;
}