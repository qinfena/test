#include <stdlib.h>
#include <assert.h>

#include "rational.h"

size_t gcd2(size_t a, size_t b) {
	assert(a <= b);
	if (!a) return b;
		size_t rem = b % a;
	return gcd2(rem, a);
}

size_t gcd(size_t a, size_t b) {
	assert(a);
	assert(b);
	if (a < b) 
		return gcd2(a, b);
	else 
		return gcd2(b, a);
}

rat rat_get (long long num, unsigned long long denom){
	rat ret = {
		.sign = (num < 0),
		.num = (num < 0) ? -num : num,
		.denom = denom,
	};
	return ret;
}

rat rat_get_normal(rat x) {
	size_t c = gcd(x.num, x.denom);
	x.num /= c;
	x.denom /= c;
	return x;
}

rat rat_get_extended(rat x, size_t f) {
	x.num *= f;
	x.denom *= f;
	return x;
}

rat rat_get_prod(rat x, rat y) {
	rat ret = {
		.sign = (x.sign != y.sign),
		.num = x.num * y.num,
		.denom = x.denom * y.denom,
	};
	return rat_get_normal(ret);
}

rat rat_get_sum(rat x, rat y) {
	size_t c = gcd(x.denom, y.denom);
	size_t ax = y.denom/c;
	size_t bx = x.denom/c;
	x = rat_get_extended(x, ax);
	y = rat_get_extended(y, bx);
	assert(x.denom == y.denom);

	if (x.sign == y.sign) {
		x.num += y.num;
	} else if (x.num > y.num) {
		x.num -= y.num;
	} else {
		x.num = y.num - x.num;
		x.sign = !x.sign;
	}
	return rat_get_normal(x);
}

int main () {
	return EXIT_SUCCESS;
}
