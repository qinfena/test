#include <stdio.h>
#include <stdlib.h>

int compare_unsigned (void const* a, void const* b){
	unsigned const* A = a;
	unsigned const* B = b;
	if (*A < *B) return -1;
	else if(*A > *B) return +1;
	else return 0;
}

int compare_int (void const* a, void const* b) {
	int const* A = a;
	int const* B = b;
	return *A - *B;
}

extern int compare_unsigned(void const* , void const*);
inline
unsigned const* bsearch_unsigned(unsigned const key[static 1],
		size_t nmeb, unsigned const base[nmeb]) {
	return bsearch(key, base, nmeb, sizeof base[0], compare_unsigned);
}

inline
void qsort_unsigned(size_t nmeb, unsigned base[nmeb]) {
	qsort(base, nmeb, sizeof base[0], compare_unsigned);
}

extren int logger_verbose(char  const*, ...);
static
int logger_ignore(char const*, ...){
	return 0;
}
logger_function* logger = logger_ignore;

static
logger_function* loggers = {
	[log_pri] = printf,
	[log_ign] = logger_ignore,
	[log_ver] = logger_verbose,
};

int main ( ) {
	return EXIT_SUCCESS;
}
