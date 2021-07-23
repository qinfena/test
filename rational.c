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
void rat_destroy(rat *rp) {
	if (rp) *rp = (rat) {0 };
}
rat* rat_init (rat *rp,
		long long num,
		unsigned long long denom) {
	if (rp) *rp = rat_get(num, denom);
	return rp;
}

rat* rat_normalize(rat* rp) {
	if (rp) *rp = rat_get_normal(*rp);
	return rp;
}
rat* rat_extend(rat* rp, size_t f){
	if (rp) *rp = rat_get_extended(*rp, f);
	return rp;
}

rat* rat_sumup(rat* rp, rat y) {
	size_t c = gcd(rp->denom, y.denom);
	size_t ax = y.denom/c;
	size_t bx = rp->denom/c;
	rat_extend(rp, ax);
	y = rat_get_extended(y,bx);
	assert(rp->denom == y.denom);

	if (rp->sign == y.sign) {
		rp->num += y.num;
	} else if (rp->num > y.num) {
		rp->num -= y.num;
	} else {
		rp->num = y.num - rp->num;
		rp->sign = !rp->sign;
	}
	return rat_normalize(rp);
}
rat* rat_rma(rat* rp, rat x, rat y) {
	return rat_sumup(rp, rat_get_prod(x,y));
}

rat const* myRat = rat_init(malloc(sizeof(rat)), 13, 7);

rat* rat_new(long long numerator,
		unsigned long long denomination) {
	return rat_init (malloc(sizeof(rat)).
			numerator,
			denominator);
}

rat const* myRat = rat_new(13, 7);

#define P99_NEW(T, ...) T ## _init(malloc(sizeof(T)), __VA_ARGS__)

rat const* myRat = P99_NEW(rat, 13, 7);

rat* rat_vinit(size_t n, rat p[n]) {
	if (p) 
		for (size_t i = 0; i < n; ++i) 
			rat_init(p+i, 0, i);
	return p;
}

rat* myRatVec = rat_vinit(44, malloc(sizeof(rat[44])));

rat* rat_vnew(size_t size) {
	return rat_vinit(size, malloc(sizeof(rat[size])));
}

int main () {
	return EXIT_SUCCESS;
}
