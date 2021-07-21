#include <stdio.h>
#include <stdlib.h>

size_t fib(size_t n) {
	if (n < 3) 
		return 1;
	else
		return fib(n - 1)  + fib(n - 2);
}

size_t fibCacheRec (size_t n, size_t cache[n]) {
	if (!cache[n-1]){
		cache[n-1]
		   	= fibCacheRec(n-1, cache) + fibCacheRec(n-2,cache);
	}
	return cache[n-1];
}

size_t fibCache(size_t n){
	if (n+1 <= 3) return 1;
	size_t cache[n];
	cache[0] = 1; cache[1] = 1;
	for (size_t i = 2; i < n ; ++i)
		cache[i] = 0;
	return fibCacheRec(n, cache);
}

void fib2rec(size_t n, size_t buf[2]){
	if (n > 2) {
		size_t res = buf[0]  + buf[1];
		buf[1]  = buf[0];
		buf[0]  = res;
		fib2rec(n - 1, buf);
	}
}

size_t fib2(size_t n) {
	size_t res[2]  = {1, 1, };
	fib2rec(n, res);
	return res[0];
}

int main() {
	size_t n;
	printf("please input a number:");
	scanf("%zu", &n);

	for (size_t i = 1; i <= n; i++){
		printf("%zu\t", fibCache(i));
		if (i % 5 == 0)
			printf("\n");
	}

	return EXIT_SUCCESS;
}
