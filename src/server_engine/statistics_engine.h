/*
 * stats.h
 *
 *  Created on: May 23, 2015
 *      Author: helgalis
 */

#ifndef SRC_SERVER_ENGINE_STATISTICS_ENGINE_H_
#define SRC_SERVER_ENGINE_STATISTICS_ENGINE_H_
#include <map>

typedef std::map<std::wstring,uint> Statistic;
Statistic curr_statistic;

void update_statistic_status();
void calculate_statistic();
void clear_statistic_data();



#endif /* SRC_SERVER_ENGINE_STATISTICS_ENGINE_H_ */
