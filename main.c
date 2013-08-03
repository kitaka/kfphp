#include <stdio.h>

#define TEST

#ifdef TEST
	#include "tests.h"
#endif

int main(void)
{
#ifdef TEST
  	printf("Running tests\n");
  	tests_run();
#else
	printf("it works very fine\n");
#endif
  	return 0;
}
