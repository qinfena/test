#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

bool leapyear(unsigned year) {
	return !(year % 4)  && ((year % 100) || !(year % 400));
}

#define DAYS_DEFORE								 	 \
	(int const[12]){							 	 \
		[0] = 0, [1] = 31, [2] = 59, [3] = 90,		 \
		[4] = 120, [5] = 151, [6]  = 181, [7] = 212, \
		[8] = 243, [9] = 273, [10] = 304, [11] = 334,\
	}
struct tm time_set_yday(struct tm t) {
	t.tm_yday += DAYS_DEFORE[t.tm_mon] + t.tm_mday; 
	if ((t.tm_mon > 1) && !leapyear(t.tm_year + 1900))
		++t.tm_yday;
	return t;
}

int main() {
	struct tm today = {
		.tm_year = 2021 - 1900,
		.tm_mon  = 7 - 1,
		.tm_mday = 20,
		.tm_hour = 16,
		.tm_min  = 0,
		.tm_sec  = 47,
	};
	printf("this year is %d, next year will be %d\n", 
			today.tm_year+1900, today.tm_year+1900+1);
	today = time_set_yday(today);
	printf("day of the year is %d\n", today.tm_yday);
	return EXIT_SUCCESS;
}
