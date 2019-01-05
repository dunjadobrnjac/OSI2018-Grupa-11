#include "PrvaIgra.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // sadrzi random funkciju - stalno vraca isti broj 
#include <time.h>   // zato treba i ova koja ima srand
#include <string>  // sl sve tri biblioteke su zbog š,č,đ,.. valjdaa
#include <cstdio>
#include <Windows.h>
int brojIgranja;

void igrajPrvuIgru(int& bodovi, Korisnik k)
{
	
	while (true)
	{
		std::ifstream input("brojigranja.txt");
		input >> brojIgranja;
		if (brojIgranja < 3)
		{
			if (prvaIgraVaranje(brojIgranja,bodovi) == 0)
				break;
		}
		else
		{
			if (prvaIgraPrava(brojIgranja,bodovi) == 0)
				break;
		}
	}
	k.brojBodova = bodovi;
	k.upisiBodove();

}
