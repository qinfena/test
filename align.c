#include <stdio.h>
#include <inttypes.h>
#include <complex.h>

void  enable_alignment_check(void);
typedef complex double cdb1;

int main(void) {
	enable_alignment_check();
	union{
		cdb1 val[2];
		unsigned char buf[sizeof(cdb1[2])];
	} toocomplex = {
		.val = { 0.5 + 0.5 * I, 0.75 + 0.75*I,},
	};

	printf("size/alignment: %zu/%zu\n", 
			sizeof(cdb1), _Alignof(cdb1));
	for (size_t offset = sizeof(cdb1); offset; offset /= 2) {
		printf("offset\%zu:\t", offset);
		fflush(stdout);
		cdb1* bp = (cdb1*) (&toocomplex.buf[offset]);
		printf("%g\t + %gI\t", creal(*bp), cimag(*bp));
		fflush(stdout);
		*bp *= *bp;
		printf("%g\t + %gI\t", creal(*bp), cimag(*bp));
		fputc('\n',stdout);
	}
}
