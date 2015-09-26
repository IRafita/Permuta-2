#include <stdlib.h>
#include "libPermutation.h"

int
main (void)
{
	int s, *v;

	s = 4;
	v = malloc (s * sizeof (int));
	if (!v)
	{
		printf ("Fatal error\n");
		return 1;
	}

	v[3] = 1;
	v[2] = 2;
	v[1] = 0;
	v[0] = 1;

	ShowVector (s, v);

	printf ("Inter 7 ?= %d\n", ParserVectorToDigitV2 (s, v));
	ShowVector (s, v);
return 0;
}
