#include "libPermutacio.h"
int main (void)
{
	int s, *v;

	s = 4;
	v = malloc (s * sizeof (int));
	if (!v)
	{
		printf ("Fatal error\n");
		return 1;
	}

	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	v[3] = 2;

	ShowVector (s, v);

	ParserPermutationDigitToVectorV2notCalc (s, v, 7, 12);

	ShowVector (s, v);
return 0;
}
