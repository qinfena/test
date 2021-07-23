#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static 
size_t numberline_inner(char const*restrict act,
		size_t numb[restrict], int base) {
	size_t n = 0;
	for (char* next = 0; act[0]; act = next) {
		numb[n]  = strtoull(act, &next, base);
		if (act == next) break;
		++n;
	}
	return n;
}

size_t* numberline(size_t size, char const lbuf[restrict size],
		size_t* restrict np, int base) {
	size_t* ret = 0;
	size_t n = 0;
	if (memchr(lbuf, 0, size)) {
		ret = malloc(sizeof(size_t[1+(2*size)/3]));
		n = numberline_inner(lbuf, ret, base);

		size_t len = n ? n : 1;
		ret = realloc(ret , sizeof(size_t[len]));
	}
	if (np) *np = n;
	return ret;
}

char* fgetline(size_t size, char s[restrict size],
		FILE * restrict stream)  {
	s[0] = 0;
	char * ret = fgets(s, size, stream);
	if (ret ) {
		char * pos = strchr(s, '\n');
		if (pos) *pos = 0;
		else ret = 0;
	}
	return ret;
}

int sprintnumbers(size_t tot, char buf[restrict tot],
		char const form[restrict static 1],
		char const sep[restrict static 1],
		size_t len, size_t nums[restrict len]) {
	char *p = buf;
	size_t const seplen = strlen(sep);
	if (len) {
		size_t i = 0;
		for (;;) {
			p += sprintf(p, form, nums[i]);
			++i;
			if (i >= len) break;
			memcpy(p, sep, seplen);
			p += seplen;
		}
	}
	memcpy(p, "\n", 2);
	return (p-buf) +1;
}


int main() {
	char lbuf[256];
	for (;;) {
		if (fgetline(sizeof lbuf, lbuf, stdin)) {
			size_t n;
			size_t* nums = numberline(strlen(lbuf)+1, lbuf, %n, 0);
			int ret = fprintnumbers(stdout, "%#zX", ",\t", n, nums);
			if (ret < 0) return EXIT_FAILURE;
			free(nums);
		} else {
			if (lbuf[0]) {
				for (;;) {
					int c = getc(stdin);
					if (c == EOF) return EXIT_FAILURE;
					if (c == '\n') {
						fprintf(stderr, "line too long: %s\n", lbuf);
						break;
					}
				}
			}else break;
		}
	}
	return EXIT_SUCCESS;	
}
