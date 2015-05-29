/*
 * response.cpp
 *
 *  Created on: May 29, 2015
 *      Author: helgalis
 */
#include "response.h"
#include "../global.h"
wchar_t response(const int code, const std::wstring * lines, const unsigned int lines_count=1){
	std::wstringstream response;
	response << code << '-' << lines[0] << END_OF_LINE;
	if(lines_count>1){
		for (int i = 0; i < lines_count-1; i++) {
			response << lines[i] << END_OF_LINE;
		}
		//TODO: what store last line in multyline message
        response << code << ' ' << lines[lines_count - 1] << END_OF_LINE;
	}
	uint response_len = response.str().length();
	wchar_t response_msg = new wchar_t[response_len+1];
	response_msg[response_len+1]=L'\0';
	memcpy((void*)response_msg,(void*)response.str().data(),response_len*sizeof(wchar_t));
	return response_msg;
}

