/*
 * commands.h
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */

#ifndef SRC_SERVER_INTERFACE_COMMANDS_H_
#define SRC_SERVER_INTERFACE_COMMANDS_H_
#include <map>

void set_text_cmd();
void set_line_cmd();
void getSavedStatisticsFileList();
const void save_cmd();
void append_cmd();
void load_cmd();
void exit_cmd();
void initialize_cmd();


void register_server_cmd();
#endif /* SRC_SRVER_INTERFACE_COMMANDS_H_ */
