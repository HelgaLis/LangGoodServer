/*
 * commands.h
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */

#ifndef SRC_SERVER_INTERFACE_COMMANDS_H_
#define SRC_SERVER_INTERFACE_COMMANDS_H_
#include <map>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
typedef void (*s_cmd)(void);
std::string curr_line;
std::map<std::string,s_cmd> server_cmd;
std::string get_cmd_args();
void set_text_cmd();
void set_line_cmd();
void getSavedStatisticsFileList();
const void save_cmd();
const void load_cmd();
const void append_cmd();
const void exit_cmd();
void initialize_cmd();


void register_server_cmd();
#endif /* SRC_SRVER_INTERFACE_COMMANDS_H_ */
