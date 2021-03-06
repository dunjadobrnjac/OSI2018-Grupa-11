#define _CRT_SECURE_NO_WARNINGS
#include "Prva.h"
#include "Druga.h"
#include "Treca.h"
#include "Cetvrta.h"
#include "Korisnik.h"
#include "Statistika.h"
#include "Varanje.h"
#include "Instalacija.h"

int main()
{
	// Set console code page to UTF-8 so console known how to interpret string data
	SetConsoleOutputCP(CP_UTF8);
	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);


	if (instalacijaZaMain())
	{
		int ulazak = 0;

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
			std::cout << u8"Omogu�eno je igranje samo prve igre." << std::endl;
			std::cout << u8"Da li �elite da igrate prvu igru --> Poga�anje slu�ajnog broja ? (Da/Ne)" << std::endl;
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
				if (k.provjeraKljuca(1))
					igrajPrvuIgru(k.brojBodova, k);
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
			if (ulazak)
				std::cout << "BringITon platforma za igre\n" << std::endl;
			ulazak = 1;
			k.ucitajBodove();
			k.ispisiBodove();

			std::cout << "\n\n========================================================" << std::endl;
			std::cout << u8"NA RASPOLAGANJU SU VAM SLJEDE�E OPCIJE:" << std::endl;
			std::cout << "--------------------------------------------------------" << std::endl;
			std::cout << u8" 1 --> Poga�anje slu�ajnog broja" << std::endl;
			std::cout << " 2 --> Kviz" << std::endl;
			std::cout << " 3 --> Loto " << std::endl;
			std::cout << u8" 4 --> Vje�ala" << std::endl;
			std::cout << u8" 5 --> Kupovina/preuzimanje klju�a" << std::endl;
			std::cout << u8" 6 --> Prikaz statistike" << std::endl;
			std::cout << " 7 --> Eksport CSV fajla" << std::endl;
			std::cout << u8" 8 --> Otkazivanje igre" << std::endl;
			std::cout << u8" 9 --> Izlaz iz igrice" << std::endl;
			std::cout << u8"10 --> Deinstalacija" << std::endl;
			std::cout << "========================================================\n" << std::endl;
			std::cout << u8"Unesite �eljenu opciju: ";
			while (!(std::cin >> brojIgre) || std::cin.get() != '\n')
			{
				std::cout << u8"----> Unos nije validan!\nUnesite �eljenu opciju: ";
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
			system("cls");
			if (brojIgre == 1)
			{
				if (k.provjeraKljuca(1))
					igrajPrvuIgru(k.brojBodova, k);
				else if (k.jednakoMinusJedan == true)
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8" Ovu igru ste ve� otkazali,stoga je ne mo�ete igrati !!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}

				else
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Morate nabaviti klju� da igrate ovu igru.\n" << std::endl;
					std::cout << u8"Da nabavite klju�, idite u glavnom meniju\nu kupovina/preuzimanje klju�a (opcija 5)." << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
			}
			else if (brojIgre == 2)
			{
				if (k.provjeraKljuca(2))
					igrajDruguIgru(k.brojBodova, k);
				else if (k.jednakoMinusJedan == true)
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8" Ovu igru ste ve� otkazali,stoga je ne mo�ete igrati !!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}

				else
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Morate nabaviti klju� da igrate ovu igru.\n" << std::endl;
					std::cout << u8"Da nabavite klju�, idite u glavnom meniju\nu kupovina/preuzimanje klju�a (opcija 5)." << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
			}
			else if (brojIgre == 3)
			{
				int pomocna = 0;
				LOTO loto;
				if (k.provjeraKljuca(3))
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Ulaz u igru je ko�tao 100 bodova. " << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(1800);
					lotoIgra(&pomocna, &k.brojBodova, &loto, k);
				}
				else if (k.jednakoMinusJedan == true)
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8" Ovu igru ste ve� otkazali,stoga je ne mo�ete igrati !!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
				else
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Morate nabaviti klju� da igrate ovu igru.\n" << std::endl;
					std::cout << u8"Da nabavite klju�, idite u glavnom meniju\nu kupovina/preuzimanje klju�a (opcija 5)." << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
			}
			else if (brojIgre == 4)
			{
				if (k.provjeraKljuca(4))
					vjesala(k.brojBodova, k);
				else if (k.jednakoMinusJedan == true)
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8" Ovu igru ste ve� otkazali,stoga je ne mo�ete igrati !!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
				else
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Morate nabaviti klju� da igrate ovu igru.\n" << std::endl;
					std::cout << u8"Da nabavite klju�, idite u glavnom meniju\nu kupovina/preuzimanje klju�a (opcija 5)." << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
			}
			else if (brojIgre == 6)
			{
				int broj;
				std::cout << "========================================================" << std::endl;
				std::cout << u8"Za koju igru �elite prikaz statistike (1/2/3/4) ?" << std::endl;
			tu:
				std::cout << "--> ";
				while (!(std::cin >> broj) || std::cin.get() != '\n')
				{
					std::cout << "----> Unos nije validan! Unesite broj igre ponovo. " << std::endl;
					std::cout << "--> ";
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
				if (broj < 1 || broj > 4)
				{
					std::cout << u8"----> Niste unijeli odgovaraju�i broj! " << std::endl;
					goto tu;
				}
				std::cout << "========================================================" << std::endl;
				sleep(800);
				ispisStatistike(broj);
			}
			else if (brojIgre == 10)
			{
				std::string odgovor;
				std::cout << "================================================================" << std::endl;
				std::cout << u8"Da li ste sigurni da �elite deinstalirati  platformu za igre? (Da/Ne)" << std::endl;
			tamo1:
				std::cout << "--> ";
				while (true)
				{
					std::cin >> odgovor;

					if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0
						|| odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
					{
						std::cout << "================================================================" << std::endl;
						sleep(800);
						break;
					}
					else
					{
						std::cout << "Unesite 'Da' ili 'Ne'...\n";
						goto tamo1;
					}
				}
				if (odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
				{
					system("cls");
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Hvala na igranju, dovi�enja!!!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(1000);
					deinstalacija();
					return 0;
				}
				else
				{
					system("cls");
					goto pocetak;
				}
			}
			else if (brojIgre == 5)
			{
				bool l = varanjePriprema(k);
				if (!l && k.jednakoMinusJedan == true)
				{
					std::cout << "========================================================" << std::endl;
					std::cout << u8" Ovu igru ste ve� otkazali,stoga je ne mo�ete igrati !!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(3200);
				}
			}
			else if (brojIgre == 8)
			{
				int broj;
				std::cout << "========================================================" << std::endl;
				std::cout << u8" Koju igru �elite da otka�ete (1/2/3/4)?" << std::endl;
			ovdje:
				std::cout << "--> ";
				while (!(std::cin >> broj) || std::cin.get() != '\n')
				{
					std::cout << "----> Unos nije validan! Unesite broj igre ponovo. " << std::endl;
					std::cout << "--> ";
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
				if (broj < 1 || broj > 4)
				{
					std::cout << u8"----> Niste unijeli odgovaraju�i broj! " << std::endl;
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
				std::cout << "================================================================" << std::endl;
				std::cout << u8"Da li ste sigurni da �elite iza�i iz platforme za igre? (Da/Ne)" << std::endl;
			tamo:
				std::cout << "--> ";
				while (true)
				{
					std::cin >> odgovor;

					if (odgovor.compare("ne") == 0 || odgovor.compare("Ne") == 0 || odgovor.compare("NE") == 0 || odgovor.compare("nE") == 0
						|| odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
					{
						std::cout << "================================================================" << std::endl;
						sleep(800);
						break;
					}
					else
					{
						std::cout << "Unesite 'Da' ili 'Ne'...\n";
						goto tamo;
					}
				}
				if (odgovor.compare("da") == 0 || odgovor.compare("Da") == 0 || odgovor.compare("dA") == 0 || odgovor.compare("DA") == 0)
				{
					system("cls");
					std::cout << "========================================================" << std::endl;
					std::cout << u8"Hvala na igranju, dovi�enja!!!" << std::endl;
					std::cout << "========================================================" << std::endl;
					sleep(1000);
					break;
				}
				else
				{
					system("cls");
					goto pocetak;
				}
			}
			system("cls");
		}
		system("pause");
		return 0;
	}
}