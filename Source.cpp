#include "Korisnik.h"
#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"
#include "CetvrtaIgra.h"
#include "Statistika.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>


int main()
{
	// Set console code page to UTF-8 so console known how to interpret string data
	SetConsoleOutputCP(CP_UTF8);
	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	std::cout << "BringITon platforma za igre\n" << std::endl;

	int resstart = 0;
	std::ifstream restart;
	restart.open("restart.txt");
	if (restart.is_open())
	{
		restart >> resstart;
		restart.close();
	}

	Korisnik k;
	k.ucitajBodove();
	
	if (!resstart)
	{
		if (k.getBrUlaza() == 0)
		{
			std::cin >> k;
			std::cout << k;
		}
		else
		{
			std::cout << "Pozdrav " << k.getIme() << "!" << std::endl;
		}
		std::cout << u8"Omoguceno je igranje samo prve igre ." << std::endl;
		std::cout << u8"Da li želite da igrate prvu igru --> Pogadanje slucajnog broja ? (Da/Ne)" << std::endl;
		std::string odgovor;
		while (true) 
		{
			std::cin >> odgovor;

			if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0
				|| odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
				break;
			else
				std::cout << " Unesite 'Da' ili 'Ne'...\n";
		}

		system("cls");
		if (odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
		{
			k.ucitajKljuc(1);
			igrajPrvuIgru(k.brojBodova, k);
			statistika(k.brojBodova, 1, true);
		}
		else
			if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0)
				return 0;
		std::ofstream restart;
		restart.open("restart.txt");
		if (restart.is_open())
		{
			restart << 1;
			restart.close();
		}
		system("cls");
	}



	int brojIgre;
	while (true)
	{
		k.ucitajBodove();
		k.ispisiBodove();
		std::cout << u8"\nPogaðanje sluèajnog broja--> 1 " << std::endl;
		std::cout << "Kviz --> 2 " << std::endl;
		std::cout << "Loto --> 3 " << std::endl;
		std::cout << u8"Vješala --> 4" << std::endl;
		std::cout << "Prikaz statistike --> 5\n" << std::endl;
		std::cout << u8"Unesite odgovarajuæi broj : ";
		std::cin >> brojIgre;
		system("cls");
		if (brojIgre == 1)
		{
			if (k.provjeraKljuca(1))
				igrajPrvuIgru(k.brojBodova,k);
			else
			{
				k.ucitajKljuc(1);
				igrajPrvuIgru(k.brojBodova,k);
			}
			statistika(k.brojBodova, 1, true);

		}
		else if (brojIgre == 2)
		{
			if (k.provjeraKljuca(2))
				igrajDruguIgru(k.brojBodova,k);
			else
			{
				k.ucitajKljuc(2);
				igrajDruguIgru(k.brojBodova,k);
			}
			statistika(k.brojBodova, 2, true);
		}
		else if (brojIgre == 3)
		{
			int pomocna = 0;
			LOTO loto;
			if (k.provjeraKljuca(3))
				lotoIgra(&pomocna, &k.brojBodova, &loto, k);
			else
			{
				k.ucitajKljuc(3);
				lotoIgra(&pomocna, &k.brojBodova, &loto, k);
			}
			statistika(k.brojBodova, 3, true);
		}
		else if (brojIgre == 4)
		{
			if (k.provjeraKljuca(4))
				vjesala(k.brojBodova,k);
			else
			{
				k.ucitajKljuc(4);
				vjesala(k.brojBodova,k);
			}
			statistika(k.brojBodova, 4, true);
		}
		else if (brojIgre == 5)
		{
			std::cout << u8"Za koju igru želite prikaz statistike (1/2/3/4) ?";
			int broj;
			std::cin >> broj;
			statistika(k.brojBodova, broj,false);
			Sleep(7000); // prikazuje statistiku 7 s
		}

		else
			std::cout << "Niste unijeli validan broj " << std::endl;
		system("cls");
	}
	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}