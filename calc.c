#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	size_t result;
	result = (7*pow(16,7) +15*(pow(16,6)+pow(16,5)+pow(16,4)+pow(16,3)+pow(16,2)+pow(16,1)+pow(16,0)))*2U+1U;
	printf("UINT_MAX = %zu\n", result);
	return EXIT_SUCCESS;
}
