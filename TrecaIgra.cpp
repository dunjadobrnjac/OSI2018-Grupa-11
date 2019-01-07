#include "TrecaIgra.h"
#include "Statistikka.h"
#include "Varanje.h"
int isTheSame(int niz[], int broj)
{
	for (int i = 0; i < 7; i++)
		if (niz[i] == broj)
			return i + 1;
	return 0;
}

bool funkcijaZaVaranje(int* brojac, int niz[], int pom, int b, int odigrani[])
{
	for (int i = 0; i < 20;i++)
		if (niz[i] == pom)
			return true;
	if (b == *brojac)
		for (int i = 0; i < 7; i++)
			if (odigrani[i] == pom)
				return true;
	if (*brojac < b)
		for (int i = 0; i < 7; i++)
			if (odigrani[i] == pom)
			{
				(*brojac)++;
			}
	return false;
}
int kolikoSmijePogoditi(Korisnik k, bool& flag)
{
	if (funkcijaKakoOdigrati(k) == 0)
		return 1;
	if (funkcijaKakoOdigrati(k) == 1)
		return rand() % 7 + 1;
	else
	{
		flag = true;
		return 7;
	}
}
int brojPogodakaFunkcija(int niz[], int odigrani[])
{
	int brojPogodaka = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 7; j++)
			if (niz[i] == odigrani[j])
				brojPogodaka++;
	return brojPogodaka;
}
int daLiJePogodjen(int potencijalniPogodak, int loto[])
{
	for (int i = 0; i < 20; i++)
		if (loto[i] == potencijalniPogodak)
			return true;
	return false;
}
int sumaBodova(int brojac)
{
	int pomocna = 0;
	while (brojac > 0)
		pomocna += (brojac--);
	return pomocna * 10;
}

void sortirajNiz(int *niz, int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		for (min = i, j = i + 1; j < n; j++)
			if (niz[j] < niz[min]) min = j;
		if (min != i)
		{
			int pom = niz[i];
			niz[i] = niz[min]; niz[min] = pom;
		}
	}
}

void ispisiRezultat(int loto[], int odigrani[], int broj, Korisnik k)
{
	std::cout << "=================================="<<std::endl;
	std::cout << u8"Odigrali ste sljedeću kombinaciju:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	sortirajNiz(odigrani, 7);
	for (int i = 0; i < 7; i++)
		std::cout << odigrani[i] << u8" ";
	std::cout << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << std::endl;
	//sortirajNiz(loto, 20);
	std::cout << "==================================" << std::endl;
	std::cout << u8"Izvučeni brojevi su:"<<std::endl;
	std::cout << "----------------------------------";
	for (int i = 0; i < 20; i++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		if (loto[i] < 10)
			std::cout << " ";
		std::cout << loto[i] << " ";
		std::cout.flush();
		sleep(1000);
	}
	std::cout << std::endl << "==================================" << std::endl;
	//std::cout << std::endl;
	sortirajNiz(loto, 20);
	sleep(1000);
	std::cout << "\n\n";
	std::cout << "==================================" << std::endl;
	std::cout << u8"KONAČNO: ==> IZVUČENI BROJEVI SU: " << std::endl;
	std::cout << "----------------------------------";
	for (int i = 0; i < 20; i++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		if(loto[i]<10)
			std::cout<< " ";
		std::cout << loto[i] << " ";
	}
	std::cout << std::endl << "==================================" << std::endl;
	std::cout << std::endl;
	//std::cout << std::endl;
	int osvojeniBodoviRezultat = sumaBodova(broj);
	std::cout << "==================================" << std::endl;
	std::cout << "Pogodili ste ukupno " << broj << " broj" << ((broj > 0) ? ((broj > 1) ? ((broj > 4) ? "eva." : "a.") : ".") : "eva.")<<std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout<< "Osvojili ste " << osvojeniBodoviRezultat << " bodova." << std::endl;
	std::cout << "==================================" << std::endl;
	//Za klasu korisnik
	k.brojBodova += osvojeniBodoviRezultat;
	//std::cout << k.brojBodova;
	k.upisiBodove();
	std::cout << std::endl;
	//Za statistiku
	char karakteri[22];
	for (int i = 0; i < 22; i++)karakteri[i] = 0;
	Stats neki = {3, Vrijeme() , osvojeniBodoviRezultat};
	upisiUTxtFajl(neki.brojIgre, neki.brojBodova, neki.datum);
	smjestiNaPravoMjesto(neki.brojIgre);
}
int odrediPoziciju(int lotoBrojevi[], int odigraniBrojevi[])
{
	while (true)
	{
		int b = rand() % 20;
		bool pomocna = false;
		for (int i = 0; i < 7; i++)
			if (lotoBrojevi[b] == odigraniBrojevi[i])
				pomocna = true;
		if (pomocna == false)
			return b;

	}
}
void lotoIgra(int* brojUlozenihBodova, int* trenutniBrojBodova, LOTO* loto, Korisnik k)
{
	//Zbog opsega nmg brojacu pristupiti van petlje
	srand(time(NULL));	//Zbog f-je random
	system("cls");
pocetak:
	loto = new LOTO;	//alokacije memorije za loto
	int pom = 0;	//Pomocni int, sluzi da preuzme broj random f-je, prije nego sto ga smjesti u lotoBrojevi
	int p = 3;
	bool pom1 = false;	//Sluzi da prihvati rezultat f-je za varanje
	for (int i = 0; i < 7; i++)
	{
		loto->odigraniBrojevi[i] = 0;
	}
	for (int i = 0;i < 7;i++)
	{
		bool p = false;//U nju smjestam rezultat izvrsavanja isTheSame f-je
		do
		{
			std::cout << u8"Unesite 7 različitih brojeva u opsegu od 1 do 45:" << std::endl;
			int j = 0;
			while (loto->odigraniBrojevi[j] != 0)
				std::cout << loto->odigraniBrojevi[j++] << " ";
			std::cout<<std::endl;
			std::cout << "Unesite " << i + 1 << ". broj :" << std::endl;
			/*if (pom < 1)
				std::cout << u8"Uneseni broj je manji od jedan, pa morate unijeti drugi broj umjesto ovog";
			if (pom > 45)
				std::cout << u8"Uneseni broj je veci od 45, pa morate unijeti drugi broj umjesto ovog";*/

			while (!(std::cin >> pom) || std::cin.get() != '\n')
			{
				std::cout << u8"***GREŠKA***    Unos nije validan. Unesite broj od 1-45" << std::endl;
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
				sleep(2000);
				system("cls");
				std::cout << u8"Unesite 7 različitih brojeva u opsegu od 1 do 45:" << std::endl;
				int j = 0;
				while (loto->odigraniBrojevi[j] != 0)
					std::cout << loto->odigraniBrojevi[j++] << u8" ";
				std::cout << std::endl;
				std::cout << "Unesite " << i + 1 << ". broj" << std::endl;
			}
			p = (pom > 45) || (pom < 0) || isTheSame(loto->odigraniBrojevi, pom);
			if (p && (pom > 0 && pom < 45))
			{
				std::cout << u8"***GREŠKA***    Dati broj je isti kao i " << isTheSame(loto->odigraniBrojevi, pom) << u8". broj pa morate unijeti " << i + 1 << u8". broj ponovo"<<std::endl;

				sleep(2000);
				system("cls");
			}
		} while (p && (pom > 0 && pom < 45));
		if (!p)
		{
			loto->odigraniBrojevi[i] = pom;
		}
		else
		{
			if (pom < 1)
				std::cout << u8"***GREŠKA***    Uneseni broj je manji od jedan, pa morate unijeti drugi broj umjesto ovog" << std::endl;
			if (pom > 45)
				std::cout << u8"***GREŠKA***    Uneseni broj je veci od 45, pa morate unijeti drugi broj umjesto ovog" << std::flush;
			i--;
			sleep(2000);
			system("cls");
		}
		system("cls");
	}
	bool flag = false;
	int brojac = 0;
	int b=kolikoSmijePogoditi(k, flag);
	for (int i = 0; i < 20; i++)
		loto->lotoBrojevi[i] = 0;
	for (int i = 0; i < 20; i++)
	{
		do
		{
			pom = rand() % 45 + 1;	//Broj mora biti u opsegu 1-45
			pom1 = funkcijaZaVaranje(&brojac, loto->lotoBrojevi, pom, b, loto->odigraniBrojevi);
		} while (pom1);
		loto->lotoBrojevi[i] = pom;
	}
	int brojPogodaka = brojPogodakaFunkcija(loto->lotoBrojevi, loto->odigraniBrojevi);
	if (flag && brojPogodaka < 4)
	{
		int i = 0;
		while (brojPogodaka < 4 && i < 8)
		{
			if (!daLiJePogodjen(loto->odigraniBrojevi[i], loto->lotoBrojevi))
			{
				loto->lotoBrojevi[odrediPoziciju(loto->lotoBrojevi, loto->odigraniBrojevi)] = loto->odigraniBrojevi[i];
				brojPogodaka = brojPogodakaFunkcija(loto->lotoBrojevi, loto->odigraniBrojevi);
			}
			i += 2;
		}
	}
	brojPogodaka = brojPogodakaFunkcija(loto->lotoBrojevi, loto->odigraniBrojevi);
	ispisiRezultat(loto->lotoBrojevi, loto->odigraniBrojevi, brojPogodaka, k);
	
	std::string odgovor;
	std::cout << u8"Da li želite opet igrati? (Da/Ne)" << std::endl;
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
		goto pocetak;
	}
}
