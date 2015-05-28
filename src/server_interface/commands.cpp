/*
 * commands.cpp

 *
 *  Created on: May 28, 2015
 *      Author: helgalis
 */
#include  "commands.h"
void save_cmd(){}

void register_server_cmd(){
	ServerCmd server_cmd;
	server_cmd["save"] =save_cmd;
}



