/*
 * interface.cpp
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */

#include "interface.h"
#include "../global.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

char* read_line() {
	char buffer[MAX_LINE_LEN];
	bool correct_line_received = false;
	int offset = 0;
	while (!correct_line_received) {
		memset(buffer, 0, sizeof(buffer));
		bool read_ok = true;
		for(offset=0; offset < sizeof(buffer),read_ok; offset++){
			char rcv_char = read_byte(read_ok);
			if (offset == 0) {
				if (rcv_char == END_OF_LINE[0] || rcv_char == END_OF_LINE[1])
					continue;
			}

			buffer[offset] = rcv_char;
			if (offset >= 2) {
				if (buffer[offset - 1] == END_OF_LINE[0]
						&& buffer[offset] == END_OF_LINE[1]) {

					correct_line_received = true;
					buffer[offset - 1] = '\0';
					break;
				}
			}


	}}
	return buffer;
}
string getFirstWord(string &fLine) {
	static std::string result;
	result.clear();

	std::size_t position = fLine.find(' ');
	if (string::npos != position)
		return fLine.substr(0, position);

	return fLine;
}
char read_byte(bool &ok) {
	//temp
	int client_sock;
	static char buffer[2];
	    memset((void*)buffer, 0, sizeof(buffer));
	    int result = recv(client_sock, buffer, 1, 0);
	    ok = result != -1;
	    return buffer[0];
}
void start_engine() {
	bool exit = false;
	while(!(exit)){
string line = read_line();
string possible_cmd = getFirstWord(line);

exit = true;
}}

