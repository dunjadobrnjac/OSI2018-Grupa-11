#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include "DrugaIgra.h"
#include <cstdlib>
#include <cstdio>
#define BP 15 // broj pitanja ovdje promjeniti ako se stave nova

struct Pitanje
{
	std::string pitanja;
	std::string tacanOdgovor;
};

void ucitajPitanja(Pitanje nizPitanja[])
{
	std::ifstream pt;
	std::string line;
	pt.open("pitanjapitanja.txt");
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
	std::string odgovor;

	int cuvar[BP];
	Pitanje nizPitanja[BP];
	
	ucitajPitanja(nizPitanja);
	RandomPitanjee(cuvar);

	for (int i = 0; i < BP; i++)
	{
		do
		{
			std::cout << nizPitanja[cuvar[i]].pitanja << std::endl;
			std::cout << "Unesite odgovor (a, b ili c):" << std::endl;
			std::cin >> odgovor;
			system("cls");
		} while (odgovor.compare("a") && odgovor.compare("b") && odgovor.compare("c"));

		if (odgovor == nizPitanja[cuvar[i]].tacanOdgovor)
			bodovi += 20;
		else if (odgovor != nizPitanja[cuvar[i]].tacanOdgovor)
			bodovi -= 30;
	}
	k.brojBodova = bodovi;
	k.upisiBodove();
}
