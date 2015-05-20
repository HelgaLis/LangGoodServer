#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
struct sockaddr_in local;
int socketInit, socketRun, socketAccept;
char buffer[300];
char cmd[20];
local.sin_family=AF_INET;
local.sin_port = htons(7054);
local.sin_addr.s_addr = htonl(INADDR_ANY);

if((socketInit = socket(AF_INET, SOCK_STREAM,0))<0){
perror("socket call failed");
exit(1);
if((socketRun = bind(socketInit,(struct sockaddr*)&local,sizeof(local)))<0){
perror("bind call failure");
exit(1);
}
socketRun = listen(socketInit,1);
if(socketRun){
perror("listen call failed");
exit(1);}
if((socketAccept=accept(socketInit,NULL,NULL))<0){
perror("accept call failed");
exit(1);}
sprintf(buffer, "Text Statistics server\n");
if((socketRun =send (socketAccept,buffer,strlen(buffer),0))<0)
    perror("socket call failed");
close(socketAccept);
exit(0);

}}
