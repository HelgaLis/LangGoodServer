/*
 * create_socket.cpp
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */
#include "create_socket.h"
#include "server_interface/message.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#define isvalidsock(s) ( ( s ) >= 0 )
int create_socket(){
struct sockaddr_in local;
	int server_sock;
	const int on = 1;
	local.sin_family=AF_INET;
	local.sin_port = htons(8656);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	server_sock = socket(AF_INET, SOCK_STREAM,0);
	if(!isvalidsock(server_sock))
		error(1, errno, "socket call failed");
	if(setsockopt( server_sock, SOL_SOCKET, SO_REUSEADDR, &on,sizeof( on )))
		   error( 1, errno, "setsockopt call failure" );

	if(bind(server_sock,(struct sockaddr*)&local,sizeof(local)))
	   error(1, errno,"bind call failure");

	if(listen(server_sock,1))
		error(1,errno,"listen call failed");

return server_sock;

}
