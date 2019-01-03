#include "Korisnik.h"
#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"
#include "CetvrtaIgra.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>

static int ukupanBrojBodovaZaSveIgre=10;

int main()
{
	// Set console code page to UTF-8 so console known how to interpret string data
	SetConsoleOutputCP(CP_UTF8);
	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	std::cout << u8"BringITon platforma za igre\n" << std::endl;

	Korisnik k;
	if (k.getBrUlaza() == 0)
	{
		std::cin >> k;
		std::cout << k;
		std::cout << u8"Omoguæeno je igranje samo prve igre ." << std::endl;
		std::cout << u8"Da li želite da igrate prvu igru --> Pogaðanje sluèajnog broja ? (da/ne)" << std::endl;
		std::string odgovor;
		std::cin >> odgovor;
		system("cls");
		if (odgovor.compare("da") == 0)
		{
			k.ucitajKljuc();
				igrajPrvuIgru(ukupanBrojBodovaZaSveIgre);
		} // ovo ne radi kako treba 
		else
			if(odgovor.compare("ne")==0)
				return 0;
		//treba dodati i ingnore kao u prvoj igri 
		system("cls");
	}
	else
	{
		int brojIgre;
		while (true)
		{
			std::cout << "Pozdrav " << k.getIme() << "!" << std::endl;
			k.ucitajBodove();
			k.ispisiBodove();
			std::cout << u8"\nPogaðanje sluèajnog broja--> 1 " << std::endl;
			std::cout << u8"Kviz --> 2 " << std::endl;
			std::cout << u8"Loto --> 3 " << std::endl;
			std::cout << u8"Vješala --> 4 \n" << std::endl;
			std::cout << u8"Unesite odgovarajuæi broj za igru koju želite da igrate : ";
			std::cin >> brojIgre;
			system("cls");
			if (brojIgre == 1)
			{
				if (k.provjeraKljuca(1))
					igrajPrvuIgru(ukupanBrojBodovaZaSveIgre);
				else
				{
					k.ucitajKljuc();
					igrajPrvuIgru(ukupanBrojBodovaZaSveIgre);
				}
		
			}
			else if (brojIgre == 2)
			{
				if (k.provjeraKljuca(2))
					igrajDruguIgru(ukupanBrojBodovaZaSveIgre);
				else
				{
					k.ucitajKljuc();
					igrajDruguIgru(ukupanBrojBodovaZaSveIgre);
				}
			}
			else if (brojIgre == 3)
			{
				int pomocna = 0;
				LOTO loto;
				if(k.provjeraKljuca(3))
					lotoIgra(&pomocna, &ukupanBrojBodovaZaSveIgre, &loto);
				else
				{
					k.ucitajKljuc();
					lotoIgra(&pomocna, &ukupanBrojBodovaZaSveIgre, &loto);
				}
			}
			else if (brojIgre == 4)
			{
				if (k.provjeraKljuca(4))
					vjesala(ukupanBrojBodovaZaSveIgre);
				else
				{
					k.ucitajKljuc();
					vjesala(ukupanBrojBodovaZaSveIgre);
				}
			}

			else
				std::cout << "Niste unijeli validan broj " << std::endl;
			std::cout << u8"\nVaš ukupan broj bodova je : " << ukupanBrojBodovaZaSveIgre << "\n";
			system("cls");
		}
	}
	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}