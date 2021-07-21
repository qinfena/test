#ifndef RATIONAL_H
#define RATIONAL_H
#include <stdbool.h>
#include <stdio.h>

typedef struct rat rat;

struct rat {
	bool sign;
	size_t num;
	size_t denom;
};

    /* 返回rat类型值的函数 */
rat rat_get(long long num, unsigned long long denom);
rat rat_get_normal(rat x);
rat rat_get_extended(rat x, size_t f);
rat rat_get_prod(rat x, rat y);
rat rat_get_sum(rat x, rat y);

#endif
