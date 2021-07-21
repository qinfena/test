#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if 1
size_t gcd2(size_t a, size_t b) {
	assert(a <= b);
	if (!a) return b;
		size_t rem = b % a;
	return gcd2(rem, a);
}
#endif

size_t gcd(size_t a, size_t b) {
	assert(a);
	assert(b);
	if (a < b) 
		return gcd2(a, b);
	else 
		return gcd2(b, a);
}
int main() {
	printf("max = %zu\n", gcd(45, 30));
	return EXIT_SUCCESS;
}
