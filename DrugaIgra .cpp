#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include "DrugaIgra.h"
#include "Varanje.h"
#include "Statistikka.h"
#include <cstdlib>
#include <cstdio>
#define BP 15 // broj pitanja ovdje promjeniti ako se stave nova

struct Pitanje
{
	std::string pitanja;
	std::string tacanOdgovor;
};

void ucitajPitanja(Pitanje nizPitanja[], int rezim)
{
	std::ifstream pt;
	std::string line;
	if (rezim == 0)
		pt.open("pitanjapitanja0.txt");
	else
		pt.open("pitanjapitanja1.txt");
	if (pt.is_open())
	{
		//std::cout << "Otvorena pitanja.txt";
		for (int i = 0; i < BP; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::getline(pt, line);
				nizPitanja[i].pitanja += line;
				nizPitanja[i].pitanja += '\n';
			}
			std::getline(pt, line);
			nizPitanja[i].tacanOdgovor += line;
		}
		pt.close();
	}
}

void RandomPitanjee(int cuvar[])
{
	int list[BP];
	for (int i = 0; i < BP; i++) {
		list[i] = i;
	}
	for (int i = 0; i < BP; i++) {
		int j = i + rand() % (BP - i);
		int temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}
	for (int i = 0; i < BP; i++) {
		cuvar[i] = list[i];
	}
}
void igrajDruguIgru(int& bodovi,Korisnik k)
{
	srand(time(NULL));
	pocetak2:
	int pomocna = bodovi;
	std::string odgovor;
	int cuvar[BP];
	Pitanje nizPitanja[BP];
	
	int rezim = funkcijaKakoOdigrati(k);
	ucitajPitanja(nizPitanja, rezim);
	RandomPitanjee(cuvar);

	for (int i = 0; i < 5; i++)
	{
		do
		{
			std::cout << "=======================================================================" << std::endl;
			std::cout << nizPitanja[cuvar[i]].pitanja << std::endl;
			std::cout << "=======================================================================" << std::endl;
			std::cout << "Unesite odgovor (a, b ili c):" << std::endl;
			std::cin >> odgovor;
			system("cls");
		} while (odgovor.compare("a") && odgovor.compare("b") && odgovor.compare("c"));

		if (odgovor == nizPitanja[cuvar[i]].tacanOdgovor)
			bodovi += 20;
		else if (odgovor != nizPitanja[cuvar[i]].tacanOdgovor)
			bodovi -= 30;
	}
	
	std::string odg;
	std::cout << u8"Da li želite opet igrati? (Da/Ne)" << std::endl;
	while (true)
	{
		std::cin >> odg;

		if (odg.compare("ne") == 0 || odg.compare("Ne") == 0 || odg.compare("NE") == 0 || odg.compare("nE") == 0
			|| odg.compare("da") == 0 || odg.compare("Da") == 0 || odg.compare("dA") == 0 || odg.compare("DA") == 0)
			break;
		else
			std::cout << "Unesite 'Da' ili 'Ne'...\n";
	}
	if (odg.compare("da") == 0 || odg.compare("Da") == 0 || odg.compare("dA") == 0 || odg.compare("DA") == 0)
	{
		system("cls");
		goto pocetak2;
	}
	k.brojBodova = bodovi;
	k.upisiBodove();
	//Za statistiku
	char karakteri[22];
	for (int i = 0; i < 22; i++)karakteri[i] = 0;
	Stats neki = { 2, Vrijeme() , bodovi-pomocna };
	upisiUTxtFajl(neki.brojIgre, neki.brojBodova, neki.datum);
	smjestiNaPravoMjesto(neki.brojIgre);
}
