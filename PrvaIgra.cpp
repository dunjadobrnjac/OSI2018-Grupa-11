#include "PrvaIgra.h"
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <time.h>  
#include <string>
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
			if (prvaIgraVaranje(brojIgranja, bodovi, k) == 0)
				break;
		}
		else
		{
			if (prvaIgraPrava(brojIgranja, bodovi, k) == 0)
				break;
		}
	}
}
