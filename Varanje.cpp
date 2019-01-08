#include "Varanje.h"
#include <iostream>
#include <fstream>

int funkcijaKakoOdigrati(Korisnik k)
{

	if (k.brojBodova < 0)
	{
		return 2;
	}
	int referentniBrojBodova = 0;
	std::ifstream datoteka;
	datoteka.open("ReferentniBrojBodova.txt");
	if (datoteka.is_open())
	{
		datoteka >> referentniBrojBodova;
		datoteka.close();
	}
	/*int brojIgranja = 0;
	if (brojIgranja % 20 < 18)
	{*/
	if (k.brojBodova > referentniBrojBodova)
		return 0;//sigurno gubi
	else if ((k.brojBodova < referentniBrojBodova) && (k.brojBodova > (referentniBrojBodova*0.6)))
		return 1;//prepusten sreci
	else
		return 2;//sigurno mora pogoditi
	/*}
	else
	{
		if (k.brojBodova < 0.7*referentniBrojBodova)
			return 1;//prepusten sreci
		else
			return 0;//sigurno gubi
	}*/
}

bool varanjePriprema(Korisnik k)
{
	int i = 0, datoteckiInt = 0;
	std::cout << u8"Za koju igricu �elite kupiti/preuzeti klju�? (1/2/3/4)" << std::endl;
ovdje:
	std::cout << "--> ";
	while (!(std::cin >> i) || std::cin.get() != '\n')
	{
		std::cout << "----> Unos nije validan! Unesite broj igre ponovo " << std::endl;
		std::cout << "--> ";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
	}
	if (i < 1 || i > 4)
	{
		std::cout << "----> Niste unijeli odgovarajuci broj! " << std::endl;
		goto ovdje;
	}
	std::ifstream datoteka;
	datoteka.open("prviPogodak.txt");
	if (datoteka.is_open())
	{
		datoteka >> datoteckiInt;
		datoteka.close();
	}
	if (!datoteckiInt && k.brojBodova > 69)
	{
		std::ofstream datoteka;
		datoteka.open("prviPogodak.txt");
		if (datoteka.is_open())
		{
			datoteka << 1;
			std::ofstream trenutniBrojBodova;
			trenutniBrojBodova.open("referentniBrojBodova.txt");
			if (trenutniBrojBodova.is_open())
			{
				trenutniBrojBodova << k.brojBodova;
				trenutniBrojBodova.close();
			}
			datoteka.close();
		}
	}
	std::ifstream datotekka;
	datotekka.open("prviPogodak.txt");
	if (datotekka.is_open())
	{
		datotekka >> datoteckiInt;
		datotekka.close();
	}
	if (datoteckiInt)
	{
		if (k.provjeraKljuca(i))
			std::cout << "Imate va�e�i klju� i mo�ete igrati igru. Ako �elite novi klju�, prvo otka�ite igru" << std::endl;
		else
			k.ucitajKljuc(i);
	}
	else
	{
		std::cout << u8"Jo� uvijek niste osvojili prvih 70 bodova, pa ne mo�ete preuzeti klju�!" << std::endl;
		sleep(2000);
	}
	return true;
}