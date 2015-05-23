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
#define isvalidsock(s) ( ( s ) >= 0 )
void error(int status, int err, const char* msg) {
	printf(msg, "%s \n");
	if (err)
		fprintf( stderr, ": %s (%d)\n", strerror(err), err);
	if (status)
		exit(status);
}

void server(int client_sock) {
	//вступает клиентское соединение
}

int main() {
	int server_sock = create_socket(), client_sock;
	struct sockaddr client_addres;
	while (true) {
		client_sock = accept(server_sock, &client_addres,
				&sizeof(client_addres));
		if (!isvalidsock(client_sock))
			error(1, errno, "accept call failed");
		server(client_sock);
	}
}

