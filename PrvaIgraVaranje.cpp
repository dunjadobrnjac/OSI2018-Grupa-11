#include "PrvaIgra.h"

int prvaIgraVaranje(int &brojIgranja,int &osvojeniBodovi)
{
	
	int odluka;
	while (true)
	{
		if (brojIgranja == 3)
			return 1;

		srand(time(0));
		int random = rand() % 101; // izabere random broj od 0 do 100 ( ako napises samo %100 onda je od 0 do 99)
		int varalica = rand() % 3 + 3; // pomocni broj pokusaja na koojem ce pogoditi broj
		int broj;
		int indeks = 0;
		int brojPokusaja = 0;
		bool postoji, neispravan, omoguciUpis;
		std::string odgovor;

		int* nizUnesenih = new int[5];

		do
		{
				do //petlja za provjeru uslova prilikom unosenja brojeva
				{
					std::cout << "======================================================" << std::endl;
					std::cout << " Unesi broj od 0 do 100 : ";
					while (!(std::cin >> broj) || std::cin.get() != '\n')
					{
						std::cout << " --> Unos nije validan! Unesite broj ponovo: ";
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
					}
					postoji = false;
					for (int j = 0; j <= indeks; ++j)
						if (nizUnesenih[j] == broj)
						{
							postoji = true;
							std::cout << u8"--> Ovaj broj je već unesen! Unesite ponovo..." << std::endl;
						}
					if (!postoji)
					{
						omoguciUpis = true;

						for (int k = 1; k <= indeks; ++k)
						{
							if ((nizUnesenih[indeks - k] > random && broj > nizUnesenih[indeks - k]) ||
								(nizUnesenih[indeks - k] < random && broj < nizUnesenih[indeks - k]))
							{
								omoguciUpis = false;
								std::cout << u8" --> Molimo Vas da obratite pažnju na prethodno \nispisanu poruku (Vaš broj nije u odgovarajućem opsegu)" << std::endl;
								break;

							}
						}
						if (omoguciUpis)
							nizUnesenih[indeks++] = broj;
					}
					if (broj < 0 || broj>100)
						std::cout << "--> Uneseni broj nije u dozvoljenom opsegu. " << std::endl;
				} while (broj < 0 || broj > 100 || postoji || !omoguciUpis);					//ogranicenje opsega
				++brojPokusaja;
				if (brojPokusaja == varalica)
					break;
					if (random < broj)																//petlja za pogadjanje brojeva
						std::cout << u8"--> Broj koji tražite je manji od unesenog broja.\n";			// moze i <<std::endl- prelazak u novi red
					else if (random > broj)
						std::cout << u8"--> Broj koji tražite je veći od unesenog broja.\n";
		} while (broj != random && brojPokusaja < varalica);


		if (broj == random)
		{
			std::cout << u8" Čestitamo! Pogodili ste broj." << std::endl;
			std::cout << "======================================================" << std::endl;
			osvojeniBodovi += 100 / brojPokusaja;
		}
		else if (brojPokusaja == varalica)
		{
			std::cout << u8" Čestitamo! Pogodili ste broj." << std::endl;
			std::cout << "======================================================" << std::endl;
			osvojeniBodovi += 100 / varalica;
		}
		
		while (true) // pitanje hoce li ponovo igrati
		{
			std::cout << u8" Da li želite ponovo da igrate? (Da/Ne)? ";
			std::cin >> odgovor;

			if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0
				|| odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
				break;
			else
				std::cout << " Unesite 'Da' ili 'Ne'...\n";

		}

		delete[] nizUnesenih;

		odluka = 1;

		brojIgranja++;
		std::ofstream output("brojigranja.txt");
		output << brojIgranja;

		if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("nE") == 0 || odgovor.compare("NE") == 0)
		{
			std::cout << " Hvala na igranju!" << std::endl;
			odluka = 0;

			break;
		}

		

		system("cls");
	}
	return odluka;
}