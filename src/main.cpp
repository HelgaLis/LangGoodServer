#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "create_socket.h";
#include  "server_interface/message.h"
#include  "server_interface/interface.h"

void start_client_session(int client_sock, int server_sock) {
	//недописано, нужно уточнять реализацию
	pid_t pid;
	        if ( (pid = fork()) == 0) {
	            std::locale::global(std::locale("ru_RU.UTF-8"));
	            close(server_sock);
	            exit(0);
	        } else {
	            close(client_sock);
	        }
}
void start_server(){
	int server_sock = create_socket();
	struct sockaddr client_address;
	socklen_t addrLen= sizeof(client_address);
	while (true) {
		int client_sock = accept(server_sock, &client_address,&addrLen);
		if (!isvalidsock(client_sock))
			error(1, errno, "accept call failed");
		start_client_session(client_sock,server_sock);
	}
}
int main() {
	start_server();
}

