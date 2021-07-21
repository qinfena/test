#include <stdio.h>
#include <stdlib.h>
#include <stdenv.h>

void printenv(char const name[static 1]) {
	if (getenv(name)) {
		char value[256]  = {0 ,};
		if (getenv_s(0, value, sizeof value, name)){
			fprintf(stderr,
					"%s: value is longer than %zu\n",
					name , sizeof value);
		}else {
			printf("%s=%s\n", name , value);
		}
	}else{
		fprintf(stderr, "%s not in environment\n", name);
	}
}
