#include <tr1/regex>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <sys/types.h>
#include "statistics_engine.h"
using namespace std;
void update_statistic_status(std::wstring word){
	uint iter =1;
	if(curr_statistic.find(word)!=curr_statistic.end())
		curr_statistic[word]+=iter;
	else
		curr_statistic[word]==iter;
}
void calculate_statistic(){
//temp
	std::wstring text_str = L"";
	tr1::regex pattern("\w+\b");
	const tr1::wsregex_iterator end;
	for(tr1::wsregex_iterator w(text_str.begin(),text_str.end(),pattern,tr1::regex_constants::icase);
			w!=end;++w){
		std::cout<<w<<std::endl;
		update_statistic_status((std::wstring)w);
	}
}
void clear_statistic_data(){}
