#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define isvalidsock(s) ( ( s ) >= 0 )
void error(int status, int err, char* msg){
  printf(msg,"%s \n");
  if ( err )
     fprintf( stderr, ": %s (%d)\n", strerror( err ), err);

  if ( status )
     exit( status );


}
int main()
{
	struct sockaddr_in local;
	int sock,  socketAccept;
	char buffer[300];
	char cmd[20];
	local.sin_family=AF_INET;
	local.sin_port = htons(7054);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	sock = socket(AF_INET, SOCK_STREAM,0);
	if(!isvalidsock(sock))
		error(1, errno, "socket call failed");
	if(bind(sock,(struct sockaddr*)&local,sizeof(local)))
		error(1, errno,"bind call failure");

	if(listen(sock,1))
		error(1,errno,"listen call failed");
	if((socketAccept=accept(sock,NULL,NULL))<0)
		error(1, errno,"accept call failed");
	sprintf(buffer, "Text Statistics server\n");
	if(write(socketAccept,buffer,strlen(buffer))<0)
		error(1, errno,"send call failed");
	for(;;){
	ssize_t n =	read(socketAccept, buffer, strlen(buffer));
	if(n<=0){
		write(socketAccept,buffer,strlen(buffer));
	}
	close(socketAccept);

	}
	exit(0);
}
