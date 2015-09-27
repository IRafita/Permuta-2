#include "libPermutacio.h"

/* s size, e entrada */
void ShowVector (int s, int *e)
{
	int i;
	for (i = s -1; i >= 0; i--)
		printf ("%2d", e[i]);
	printf ("\n");
}

int Possiblitats (int s, int*e)
{
	int tn, tv;
	int o, ele, rep;

	tn = e[--s];
	o = 1; ele = 1; rep = 1;

	while (s--)
	{
		tv = tn;
		tn = e[s];
		if (tn == tv)
			rep++;
		else
			rep = 1;
		o = (o * ++ele) / rep; /* Primer feia la divisio, cosa que malformava el resultat */
	}
	return o;
}

void MouElementDreta (int p, int *e)
/* p es la posicio on se vol moure tot */
{
	int t = e[p];
	e[p] = e[p-1];
	while (--p)
		e[p] = e[p-1];
	e[0] = t;
}

/* Nomes necessita reordenar el que entrem */
void cacaParserPermutationDigitToVector (int d, int s, int *e)
/*
 d digit que se vol transformar
 s tamany d'e
 e es la entrada que se transformara en sortida
*/
{
	int p; /* un punter */
	int i = s; /* digits que falten per trobar */

	while (d)
	{
		/* estan parlant molt fort, no me consentro per a res. ja ho farem en un futur proxim */

		p = d/i;
		d %= i--;

		MouElementDreta (p, e);
	}
}

int
/*
 0 tot correcte
 -1 no s'ha pogut fer
*/
ParserPermutationDigitToVectorV2notCalc (s, e, T, Pos)
int s;	/* tamany del vector e */
int*e;	/* vector que transformarem al desitjat */ /* se suposa que esta ordenat pel complert */
int T;	/* valor en que volem transformar el vector */
int Pos;	/* Possiblitats totals del vector */
{
	int tvr;	/* temporal variable repetit */
	int tr;		/* temporal repetit */

	int ti;		/* temporal index */

	int b;		/* buscador */

	int i, j;	/* index */
	while (T)
	{	
		//if (tps)
		/* Petit canvi, ja que fa divisio entera i no interesa amb ti = T / tps */
			ti = (T * s) / Pos;
		//else
		//	return -2;

/* Feina de buscar el mes petit que conte la possicio */
		b = -1; /* per detectar els events sense fer masa codi */
		tvr = e[ti];
		tr = 1;
/* busquem el minim */
		for (i = ti -1; i >= 0; i--)
		{
			if (e[i] == tvr)
			{	tr++;
			} else
			{	b = i+1; /* trobat el valor minim */
				break;
			}
		}
		if (b == -1) /* cas que sigui zero */
			b = 0;
/* Acabem de comptar el tot */
		j = -1;
		for (i = ti +1; i < s; i++)
		{
			if (e[i] == tvr)
			{	tr++;
			} else
			{	j = i-1; break; }
		}
/* Cal reordenar tot i posar el nou element a lloc */
		if (j != -1) /* cas que cal reordenar */
		{
			for (i = j; i < s -1; i++)
				e[i] = e[i +1];
			e[s -1] = tvr;
		}

/* operació intuitiva que em de fer */
		T -= (Pos * b) / s; /* el canvi per evitar errors numerics */
		Pos = (Pos * tr) / s--;
		if (!s)
			return -1;
	}
/* Nomes queda capgirar el final */
	i = 0; j = s -1;
	while (i <= j)
	{
		tr = e[i];
		e[i++] = e[j];
		e[j--] = tr;
	}
return 0;
}
