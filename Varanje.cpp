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
	if (k.brojBodova > referentniBrojBodova)
		return 0;
	else if ((k.brojBodova < referentniBrojBodova) && (k.brojBodova > (referentniBrojBodova*0.6)))
		return 1;
	else
		return 2;
}

bool varanjePriprema(Korisnik k)
{
	int i = 0;
	int datoteckiInt = 0;
	std::cout << "========================================================" << std::endl;
	std::cout << u8"Za koju igricu želite kupiti/preuzeti kljuè? (1/2/3/4)" << std::endl;
ovdje:
	std::cout << "--> ";
	while (!(std::cin >> i) || std::cin.get() != '\n')
	{
		std::cout << "----> Unos nije validan! Unesite broj igre ponovo. " << std::endl;
		std::cout << "--> ";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
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
		{
			std::cout << "========================================================" << std::endl;
			std::cout << "Imate važeæi kljuè i možete igrati igru.\nAko želite novi kljuè, prvo otkažite igru" << std::endl;
			std::cout << "========================================================" << std::endl;
			sleep(2800);
		}
		else
			k.ucitajKljuc(i);
	}
	else
	{
		std::cout << "========================================================" << std::endl;
		std::cout << u8"Još uvijek niste osvojili prvih 70 bodova,\npa ne možete preuzeti kljuè!" << std::endl;
		std::cout << "========================================================" << std::endl;
		sleep(2800);
	}
	return true;
}