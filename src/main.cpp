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
void error(int status, int err,const char* msg){
  printf(msg,"%s \n");
  if ( err )
     fprintf( stderr, ": %s (%d)\n", strerror( err ), err);
  if ( status )
     exit( status );
}

void server(int peer, struct sockaddr_in *addr){
	char buffer[300];
	sprintf(buffer, "Text Statistics server\n");
		if(write(peer,buffer,strlen(buffer))<0)
			error(1, errno,"send call failed");

		ssize_t n =	read(peer, buffer, strlen(buffer));
		puts(buffer);
		if(n<=0){

			write(peer,buffer,strlen(buffer));
		}
}

int main()
{
	struct sockaddr_in local;
	int sock,  peer;
	char buffer[300];
	char cmd[20];
	const int on = 1;
	local.sin_family=AF_INET;
	local.sin_port = htons(8656);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	sock = socket(AF_INET, SOCK_STREAM,0);
	if(!isvalidsock(sock))
		error(1, errno, "socket call failed");
	if(setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &on,sizeof( on )))
		   error( 1, errno, "setsockopt call failure" );

	if(bind(sock,(struct sockaddr*)&local,sizeof(local)))
	   error(1, errno,"bind call failure");

	if(listen(sock,1))
		error(1,errno,"listen call failed");
	peer=accept(sock,NULL,NULL);
	if(!isvalidsock(peer))
		error(1, errno,"accept call failed");
	server(sock,&local);

	close(peer);
	exit(0);
	}


