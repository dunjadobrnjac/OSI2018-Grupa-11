#define _CRT_SECURE_NO_WARNINGS
#include "PrvaIgra.h"
#include "DrugaIgra.h"
#include "TrecaIgra.h"
#include "CetvrtaIgra.h"
#include "Korisnik.h"
#include "Statistikka.h"
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
			//statistika(k.brojBodova, 1, true);
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
	else
		std::cout << "Pozdrav " << k.getIme() << "!\n" << std::endl;

	int brojIgre;
	while (true)
	{
	pocetak:
		k.ucitajBodove();
		k.ispisiBodove();
	
		std::cout << "\n\n========================================================" << std::endl;
		std::cout << "NA RASPOLAGANJU SU VAM SLJEDECE OPCIJE:" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << u8" 1 --> Pogaðanje sluèajnog broja" << std::endl;
		std::cout << " 2 --> Kviz" << std::endl;
		std::cout << " 3 --> Loto " << std::endl;
		std::cout << u8" 4 --> Vješala" << std::endl;
		std::cout << " 5 --> Kupovina/preuzimanje kljuèa" << std::endl;
		std::cout << u8" 6 --> Prikaz statistike" << std::endl;
		std::cout << " 7 --> Eksport CSV fajla" << std::endl;
		std::cout << u8" 8 --> Otkazivanje igre"<<std::endl;
		std::cout << u8" 9 --> Izlaz iz igrice"<<std::endl;
		std::cout << "========================================================\n" << std::endl;
		std::cout << u8"Unesite zeljenu opciju: ";
		while (!(std::cin >> brojIgre) || std::cin.get() != '\n')
		{
			std::cout << "----> Unos nije validan!\nUnesite zeljenu opciju: ";
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
		system("cls");
		if (brojIgre == 1)
		{
			if (k.provjeraKljuca(1))
				igrajPrvuIgru(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(4500);
			}
		}
		else if (brojIgre == 2)
		{
			if (k.provjeraKljuca(2))
				igrajDruguIgru(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(4500);
			}
		}
		else if (brojIgre == 3)
		{
			int pomocna = 0;
			LOTO loto;
			if (k.provjeraKljuca(3))
			{
				std::cout << u8"Ulaz u igru je koštao 100 bodova"<<std::endl;
				sleep(2000);
				lotoIgra(&pomocna, &k.brojBodova, &loto, k);
			}
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(4500);
			}
		}
		else if (brojIgre == 4)
		{
			if (k.provjeraKljuca(4))
				vjesala(k.brojBodova,k);
			else
			{
				std::cout << u8"Morate nabaviti kljuè da igrate ovu igru." << std::endl;
				std::cout << u8"Da nabavite kljuè, idite u glavnom meniju u kupovina/preuzimanje kljuèa(opcija 6)." << std::endl;
				sleep(4500);
			}
		}
		else if (brojIgre == 6)
		{
			int broj;
			std::cout << u8"Za koju igru želite prikaz statistike (1/2/3/4) ?"<<std::endl;
		tu:
			std::cout << "--> ";
			while (!(std::cin >> broj) || std::cin.get() != '\n')
			{
				std::cout << "----> Unos nije validan! Unesite broj igre ponovo " << std::endl;
				std::cout << "--> ";
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
			}
			if (broj < 1 || broj > 4)
			{
				std::cout << "----> Niste unijeli odgovarajuci broj! " << std::endl;
				goto tu;
			}
			ispisStatistike(broj);
		}
		else if (brojIgre == 5)
		{
			bool l = varanjePriprema(k);
		}
		else if (brojIgre == 8)
		{
			int broj;
			std::cout << u8" Koju igru želite da otkažete (1/2/3/4)?" << std::endl;
		ovdje:
			std::cout << "--> ";
			while (!(std::cin >> broj) || std::cin.get() != '\n')
			{
				std::cout << "----> Unos nije validan! Unesite broj igre ponovo " << std::endl;
				std::cout << "--> ";
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
			}
			if (broj < 1 || broj > 4)
			{
				std::cout << "----> Niste unijeli odgovarajuci broj! " << std::endl;
				goto ovdje;
			}
			k.otkaziIgru(broj);
		}
		else if (brojIgre == 7)
		{
			pisiUCSV();
		}
		else if (brojIgre == 9)
		{
			std::string odgovor;
			std::cout << "Da li ste sigurni da želite izaci iz platforme za igre? (Da/Ne)" << std::endl;
			std::cout << "--> ";
			while (true)
			{
				std::cin >> odgovor;

				if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0
					|| odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
					break;
				else
					std::cout << "Unesite 'Da' ili 'Ne'...\n";
			}
			if (odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
			{
				system("cls");
				std::cout << u8"Hvala na igranju, dovidenja!!!" << std::endl;
				sleep(1500);
				break;
			}
			else
			{
				system("cls");
				goto pocetak;
			}
		}
	}
	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}