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
	int brojIgre;
	while (true)
	{
		std::cout << u8"Pogaðanje sluèajnog broja--> 1 " << std::endl;
		std::cout << u8"Kviz --> 2 " << std::endl;
		std::cout << u8"Loto --> 3 " << std::endl;
		std::cout << u8"Vješala --> 4 " << std::endl;
		std::cout << u8"Unesite odgovarajuæi broj za igru koju želite da igrate : ";
		std::cin >> brojIgre;
		system("cls");
		if (brojIgre == 1)
			igrajPrvuIgru(ukupanBrojBodovaZaSveIgre);
		else if (brojIgre == 2)
			igrajDruguIgru(ukupanBrojBodovaZaSveIgre);
		else if (brojIgre == 3)
		{
			int pomocna=0;
			LOTO loto;
			lotoIgra(&pomocna, &ukupanBrojBodovaZaSveIgre, &loto);
		}
		else if (brojIgre == 4)
			vjesala(ukupanBrojBodovaZaSveIgre);
			
		else
			std::cout << "Niste unijeli validan broj " << std::endl;
		std::cout << u8"\nVaš ukupan broj bodova je : " << ukupanBrojBodovaZaSveIgre << "\n";
		system("cls");
	}
	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}