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
#include "response.h"
#include "../server_engine/statistics_engine.h"
#include "../server_engine/encode.h"
//typedef void (*s_cmd)(void);
//std::map<std::string,s_cmd> RegCmd;
std::string get_cmd_args(){
	std::string args;
	return args;
}
const void save_cmd(){
	std::string arg = get_cmd_args();
		std:: wstring name = encode(arg);
		std:: wstring *msg;
		if(name.length()==0){
			msg<-L"Print in name argument";
			response(404,msg);
		}
		std::wstringstream wss;
		save_statistic(name);
		msg<-wss<<L"Statistic "<<name<<L" saved";
		response(202,msg);
}
const void load_cmd(){

}

const void append_cmd(){}
const void exit_cmd(){}

void register_server_cmd(){
//	std::map<std::string,s_cmd> server_cmd;
	server_cmd.insert(std::make_pair("save",&save_cmd));
	server_cmd.insert(std::make_pair("load",&load_cmd));
	server_cmd.insert(std::make_pair("append",&append_cmd));
	server_cmd.insert(std::make_pair("exit",&exit_cmd));
}



