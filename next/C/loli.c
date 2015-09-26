#include "libPerm.h"

int main (void)
{
	int size, *vector, i;

	size = 5;
	vector = malloc (size * sizeof (int));

	vector[0] = 0;
	vector[1] = 1;
	vector[2] = 2;
	vector[3] = 3;
	vector[4] = 4;
	/*vector[5] = 2;
	vector[6] = 2;*/

	ShowVector (size, vector);


	for (i = 0; i < 10; i++)
	{
		NextPermutation (size, vector);
		ShowVector (size, vector);
	}

	printf ("Altre\n");
	while (!NextPermutationV2 (size, vector))
		ShowVector (size, vector);

	printf ("Un cop acabat\n");
	ShowVector (size, vector);

free (vector);
return 0;
}
