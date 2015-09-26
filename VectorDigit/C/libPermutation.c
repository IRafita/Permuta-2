#include "libPermutation.h"

void ShowVector (int s, int *e)
/* s size, e entrada */
{
	int i;
	for (i = 0; i < s; i++)
		printf ("%3d", e[i]);
	printf ("\n");
}

void MoveVectorLeft (int s, int p, int *e)
/*
 s size
 p posicio
 e entrada
*/
{
	int i, t = e[p];
	for (i = p; i < s -1; i++)
		e[i] = e[i+1];
	e[s-1] = t;
}
/*
	necessari per a poder acabar el programa quan toca
	0 correcte
	1 final, no te sentit buscar el seguent quan ja no n'hi ha
	2 resultat sense sentit ;-)
*/
int
NextPermutation (int s, int *v)
{
	int i, j, tt, tM;

	i = s-1;
	tM = v[i];

	while (i--)
	{
		tt = v[i];
		if (tt < tM)
		{
			for (j = i +1; j < s; j++)
			{
				tM = v[j];
				if (tt < tM)
				{
					v[i] = v[j];
					v[j] = tt;
					return 0; /* tot correcte */
				}
			}
			return 2; /* si entres al condicional ja estas teoricament al final i esta assegurat */
		} else
		{
			tM = tt;
			MoveVectorLeft (s, i, v);
		}
	}
return 1;
}

int ParserVectorDigit (int s, int *e)
{
	int i, o = 0;

i = 0;
o = i; /* nomes per evitar warnings de no esser usats */
	/* posiblitat * busqueda/ total */

	/* pupa cap, ara no tic pel que haura d'estar, aixi que ja ni se parlrar , llavors rrr aaa rrr mmm deu */
return o;
}

/* Anira al contrari del que estem costumats a llegir, (de petit a gran)
Ja que ara se que es un sistema que calcularem poc a poc les permutacions, sense estres
*/
int ParserVectorToDigitV2 (s, e) /* sense dibuix */
int s; /* Size the vector */
int*e; /* vector */
{
	int i, j;	/* index */
	int Pos;	/* possiblitats possibles */
	int D;		/* resultat de tornada */
	int repe;	/* cops que se repeteix */
	int tr;		/* valor tmp, el que se repeteix */
	int b;		/* valor de la busqueda */

	Pos = 1; /* Inicialitzem el valor ;) */
	D = 0;
	i = 1;
	while (i < s)
	{
/* Apartat del buscador */
		tr = e[i];
		repe = 1;
		b = -1; /* donem un resultat impossible 'controlar' */
		for (j = 0; j < i; j++)
		{
			if (tr < e[j])
			{
				if (b == -1)
					b = j;
				break;
			}else if (tr == e[j])
			{
				if (b == -1)
					b = j;
				repe++;
			}
		}
		if (b == -1)
			b = i;
/* Ara nomes queda ordenar els elements correctament */
		for (j = i; j >= b; j--)
			e[j] = e[j -1];
		e[b] = tr;

/* Final, ja nomes cal fer la suma */
		Pos *= ++i / repe;
		D += (Pos * b) / i;
	}
return D;
}
