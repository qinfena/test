#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum0(size_t len, double const* a) {
	double ret = 0.0;
	for (size_t i = 0; i < len; ++i){
		ret += *(a + i);
	}
	return ret;
}
double sum1(size_t len, double const* a) {
	double ret = 0.0;
	for (double const* p = a; p < a+len; ++p) {
		ret += *p;
	}
	return ret;
}
double sum2(size_t len, double const* a) {
	double ret = 0.0;
	for (double const*const aStop = a+len; a < aStop; ++a) {
		ret += *a;
	}
	return ret;
}

double sum3(size_t len, double const* a) {
	double ret = 0.0;
	double const* p = a + len -1;
	do {
		ret += *p;
		--p;
	}while (p > a);
	return ret;
}

double sum4(size_t len, double const* a) {
	double ret = 0.0;
	double const* p = a + len -1;
	do {
		if (isinf(*p)) {
			fprintf(stderr,
				"element \%tu of array at \%p is infinite\n",
				p - a,
				((void*)a));
			return *p;
		}
		ret += *p;
		--p;
	}while (p > a);
	return ret;
}

int main() {
	double A[7] = {0, 1, 2, 3, 4, 5, 6, };
	double s0_7 = sum0(7,&A[0]);
	double s1_6 = sum0(6,&A[1]);
	double s2_3 = sum0(3,&A[2]);

	printf("s0_7 = %lf\ns1_6 = %lf\ns2_3 = %lf\n", s0_7, s1_6, s2_3);

	double B[2] = {0.0, 1.0 };
	double *p = &B[0];
	printf("element %g\n", *p);
	p += 3;

	return EXIT_SUCCESS;
}


