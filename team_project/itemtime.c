#include "head.h"
#define Item_time 10

void itemtime(time_t* t) {
	*t += Item_time;
}

void pause_item(time_t* t) {
	if (*t > 0)
	*t += time(0) - Stop_time ;
}