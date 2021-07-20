#include <stdio.h>
#include <stdlib.h>

#define CORVID_NAME /**/ \
	(char const*const[corvid_num] ){ \
		[chough] = "chough",     \
		[raven] = "raven", 		 \
		[magpie] = "magpie" ,	\
		[jay]  = "jay" ,	\
	}

int main () {
	enum corvid { magpie, raven, jay,chough, corvid_num} ;
#if 0
	char const * const bird[corvid_num] = {
		[raven] = "raven",
		[magpie] = "magpie",
		[jay]  = "jay",
	};
#endif

	for (unsigned i = 0; i < corvid_num; ++i) {
		printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
	}
	return EXIT_SUCCESS;
}
