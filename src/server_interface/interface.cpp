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

#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

char* read_line() {
	char buffer[MAX_LINE_LEN] = "";
	return buffer;
}
void start_engine() {
	string line = read_line();
}

