#include "libPermutacio.h"

void cp (int s, int*e, int*o)
{	while (s--)
		o[s] = e[s];
}

int main (void)
{
	int s, *v, *t;
	int i;
	int Pos;

	s = 25;
	v = malloc (s * sizeof (int));
	t = malloc (s * sizeof (int));
	if (!v || !t)
	{
		printf ("Fatal error\n");
		return 1;
	}

	for (i = 0; i < 23; i++)
		v[i] = 0;
	for (i = 23; i < s; i++)
		v[i] = 1;

	ShowVector (s, v);

	Pos = Possiblitats (s, v);

	printf ("Em contat %d possiblitats\n", Pos);

	for (i = 0; i < Pos; i++)
	{
		cp (s, v, t);
		if (ParserPermutationDigitToVectorV2notCalc (s, t, i, Pos))
			printf ("Greu error %d\n", i);
		printf ("%3d - ", i);
		ShowVector (s, t);
	}
return 0;
}
