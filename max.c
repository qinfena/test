#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <tgmath.h>
#include "test.h"


#ifndef MAX
# error "we not need max"
#endif

int main () {
	size_t a=0;
	unsigned int c=-1;
	unsigned long d=-1;
	unsigned long int e=-1;
	printf("max = %zu\n", a - 1);
	printf("max2 = %u\n", -1);
	size_t b=-1;
	printf("max3 = %zu\n", b);
	printf("max3 = %zu\n", b + SIZE_MAX);
	printf("max3 = %zu\n", SIZE_MAX + SIZE_MAX);
	printf("maxc = %u\n", c);
	printf("maxd = %lu\n", d);
	printf("maxe = %lu\n", e);

	return EXIT_SUCCESS;
}
