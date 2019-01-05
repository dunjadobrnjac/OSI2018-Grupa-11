#include "Varanje.h"

int funkcijaKakoOdigrati(Korisnik k)
{
	//return 2;
	if (k.brojBodova < 0)
	{
		k.brojUlozenihBodova -= k.brojBodova;
		k.brojBodova = 0;
	}
	int brojIgranja = 0;
	if (brojIgranja % 20 < 18)
	{
		if (k.brojBodova > k.brojUlozenihBodova)
			return 2;//sigurno mora pogoditi
		else if (k.brojBodova > k.brojUlozenihBodova*0.6 && k.brojBodova < k.brojUlozenihBodova)
			return 1;//prepusten sreci
		else
			return 0;//sigurno gubi
	}
	else
	{
		if (k.brojBodova < 0.7*k.brojUlozenihBodova)
			return 1;//prepusten sreci
		else
			return 0;//sigurno gubi
	}
}