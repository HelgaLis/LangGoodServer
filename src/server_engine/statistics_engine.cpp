#include <tr1/regex>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <sys/types.h>
#include "statistics_engine.h"
using namespace std;
void update_statistic_status(){}
void calculate_statistic(){
//temp
	std::wstring text_str = L"";
	tr1::regex pattern("\w+\b");
	const tr1::wsregex_iterator end;
	for(tr1::wsregex_iterator w(text_str.begin(),text_str.end(),pattern,tr1::regex_constants::icase);
			w!=end;++w){
		std::cout<<w<<std::endl;
	}
}
void clear_statistic_data(){}
