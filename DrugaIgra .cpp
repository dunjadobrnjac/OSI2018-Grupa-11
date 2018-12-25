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
/*void UcitajTacneOdgovore(char niz[])
{
	std::ifstream Odg;
	Odg.open("odgovori.txt");
	if (Odg.is_open())
	{
		for (int i = 0; i < 15; i++)
		{
			Odg >> niz[i];
		}
		Odg.close();
	}
}*/
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
				//strcat(nizPitanja[i].pitanja, line);
			}
			std::getline(pt, line);
			nizPitanja[i].tacanOdgovor += line;
		}
		pt.close();
	}
}
/*int RandomPitanje(int cuvar[])
{
	std::random_device randomGenerator;
	int index =abs((int)randomGenerator() % 14);
	int brojac = 0;
	for (int i = 0; i < 15; i++)
	{
		if (index == cuvar[i])
			brojac++;
	}
	if (brojac == 0)
		return index;
	else
		return RandomPitanje(int cuvar[]);
}
*/
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
void igrica2(int& bodovi)
{
	srand(time(NULL));
	std::string odgovor;
	//int bodovi = 0;
	//char niz[15];
	int cuvar[BP];
	Pitanje nizPitanja[BP];
	//UcitajTacneOdgovore(niz);
	ucitajPitanja(nizPitanja);
	RandomPitanjee(cuvar);
	//for (int i = 0; i < 15; i++)
		//std::cout << niz[i] ;
	for (int i = 0; i < BP; i++)
	{
		//std::cout << nizPitanja[cuvar[i]].pitanja << std::endl;
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
	std::cout << "Broj bodova je " << bodovi;
	//getchar();
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000); // Omogucen unos è, æ, ž,š ,ð
	int a = 1000;
	igrica2(a);
	getchar();
}