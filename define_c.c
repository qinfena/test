#include <stdio.h>

#define my_print2(...) printf(__VA_ARGS__)

int main () {
	my_print2("hello worll!\n");
	return 0;
}
