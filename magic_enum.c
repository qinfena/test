#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {
	char const* sign_rep[4]  = {
		[1] = "sign and magnitude",
		[2] = "one's complement",
		[3] = "two's complemtnt",
		[0] = "weird" ,
	};
	enum { sign_magic = -1&3};
	printf("sign representation:%s[%u].\n", sign_rep[sign_magic], UINT_MAX);
	return EXIT_SUCCESS;
}
