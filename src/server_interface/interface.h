/*
 * interface.h
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */

#ifndef SRC_SERVER_INTERFACE_INTERFACE_H_
#define SRC_SERVER_INTERFACE_INTERFACE_H_
using namespace std;
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void start_engine();
char read_byte(bool & ok);
char * read_line();
string getFirstWord(string &fLine);
void sendMsg();


#endif /* SRC_SERVER_INTERFACE_INTERFACE_H_ */
