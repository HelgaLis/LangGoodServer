/*
 * commands.cpp

 *
 *  Created on: May 28, 2015
 *      Author: helgalis
 */

#include  "commands.h"
#include <map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
//typedef void (*s_cmd)(void);
//std::map<std::string,s_cmd> RegCmd;
const void load_cmd(){}
const void save_cmd(){}
const void exit_cmd(){};

void register_server_cmd(){
//	std::map<std::string,s_cmd> server_cmd;
	server_cmd.insert(std::make_pair("save",&save_cmd));
	server_cmd.insert(std::make_pair("load",&load_cmd));
	server_cmd.insert(std::make_pair("exit",&exit_cmd));
}



