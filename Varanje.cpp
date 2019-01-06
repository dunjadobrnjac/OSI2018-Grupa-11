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
	std::cout << u8"Za koju igricu želite kupiti/preuzeti kljuc? (1/2/3/4)" << std::endl;
	std::cin >> i;
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
		k.ucitajKljuc(i);
	else
	{
		std::cout << u8"Još uvijek niste osvojili prvih 70 bodova, pa ne možete preuzeti kljuè." << std::endl;
		sleep(3000);
	}
	return true;
}
