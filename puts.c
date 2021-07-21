#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

void puts_safe(char const s[static 1]){
	static bool failed = false;
	if (!failed && puts(s) == EOF) {
		perror("can't output to terminal:");
		failed = true;
		errno = 0;
	}
}

int  main  () {

	return EXIT_SUCCESS;
}

