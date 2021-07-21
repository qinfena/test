#include <stdio.h>
#include <stdlib.h>

char * fgets_manually(char s[restrict], int n,
						FILE * restrict stream){
	if (!stream) return 0;
	if (!n) return s;
	for (size_t pos = 0; pos < n -1; ++pos) {
		int val = fgetc(stream);
		switch (val) {
			case EOF: if (feof(stream)) {
						  s[pos] = 0;
						  return s;
					  }else {
						  return 0;
					  }
			case '\n': s[pos]  = val; s[pos+1] = 0; return s;
			default: s[pos]  = val;
		}
	}
	s[n-1]  = 0;
	return s;
}
int main() {
	
	return EXIT_SUCCESS;
}
