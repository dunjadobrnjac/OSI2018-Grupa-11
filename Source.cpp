#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"
#include "CetvrtaIgra.h"
#include "Korisnik.h"
#include "Statistika.h"
#include "Varanje.h"
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
		std::cout << u8"Omoguæeno je igranje samo prve igre ." << std::endl;
		std::cout << u8"Da li želite da igrate prvu igru --> Pogaðanje sluèajnog broja ? (Da/Ne)" << std::endl;
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
		std::cout << u8"\n 1 --> Pogaðanje sluèajnog broja" << std::endl;
		std::cout << " 2 --> Kviz" << std::endl;
		std::cout << " 3 --> Loto " << std::endl;
		std::cout << u8" 4 --> Vješala" << std::endl;
		std::cout << " 5 --> Prikaz statistike" << std::endl;
		std::cout << u8" 6 --> Kupovina/preuzimanje kljuèa \n" << std::endl;
		std::cout << u8" Unesite odgovarajuæi broj: ";
		std::cin >> brojIgre;
		system("cls");
		if (brojIgre == 1)
		{
			if (k.provjeraKljuca(1))
				igrajPrvuIgru(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(6000);
			}
			statistika(k.brojBodova, 1, true);

		}
		else if (brojIgre == 2)
		{
			if (k.provjeraKljuca(2))
				igrajDruguIgru(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(6000);
			}
			statistika(k.brojBodova, 2, true);
		}
		else if (brojIgre == 3)
		{
			int pomocna = 0;
			LOTO loto;
			if (k.provjeraKljuca(3))
			{
				std::cout << u8"Ulaz u igru je koštao 100 bodova"<<std::endl;
				sleep(3000);
				k.brojBodova -= 100;
				lotoIgra(&pomocna, &k.brojBodova, &loto, k);
			}
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(6000);
			}
			statistika(k.brojBodova, 3, true);
		}
		else if (brojIgre == 4)
		{
			if (k.provjeraKljuca(4))
				vjesala(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(6000);
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
		else if (brojIgre == 6)
		{
			bool l=varanjePriprema(k);
		}
		else
			std::cout << "Niste unijeli validan broj " << std::endl;
		system("cls");
	}
	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}