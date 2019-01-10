#include "Instalacija.h"

void instalacija()
{
	std::ofstream datoteka;
	datoteka.open("bodovi.txt");
	if (datoteka.is_open())
	{
		datoteka << 10 << " " << 0;
		datoteka.close();
	}
	datoteka.open("brojIgranja.txt");
	if (datoteka.is_open())
	{
		datoteka << 0;
		datoteka.close();
	}
	datoteka.open("brojUlaza.txt");
	if (datoteka.is_open())
	{
		datoteka << 0;
		datoteka.close();
	}
	datoteka.open("ime.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("prviPogodak.txt");
	if (datoteka.is_open())
	{
		datoteka << 0;
		datoteka.close();
	}
	datoteka.open("redKljucevaPoTrajanjima.txt");
	if (datoteka.is_open())
	{
		datoteka << 1 << std::endl;
		datoteka << 1 << std::endl;
		datoteka << 1 << std::endl;
		datoteka << 1;
		datoteka.close();
	}
	datoteka.open("referentniBrojBodova.txt");
	if (datoteka.is_open())
	{
		datoteka << 0;
		datoteka.close();
	}
	datoteka.open("restart.txt");
	if (datoteka.is_open())
	{
		datoteka << 0;
		datoteka.close();
	}
	datoteka.open("StatistikaZaPrvuIgru.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("StatistikaZaDruguIgru.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("StatistikaZaTrecuIgru.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("StatistikaZaCetvrtuIgru.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("Temp.txt");
	if (datoteka.is_open())
		datoteka.close();
	datoteka.open("trajanjePrvaIgra.txt");
	if (datoteka.is_open())
	{
		datoteka << 0 << std::endl << 0;
		datoteka.close();
	}
	datoteka.open("trajanjeDrugaIgra.txt");
	if (datoteka.is_open())
	{
		datoteka << 0 << std::endl << 0;
		datoteka.close();
	}
	datoteka.open("trajanjeTrecaIgra.txt");
	if (datoteka.is_open())
	{
		datoteka << 0 << std::endl << 0;
		datoteka.close();
	}
	datoteka.open("trajanjeCetvrtaIgra.txt");
	if (datoteka.is_open())
	{
		datoteka << 0 << std::endl << 0;
		datoteka.close();
	}
}
bool instalacijaZaMain()
{
	int i = 0;
	std::ifstream datoteka1;
	datoteka1.open("instalacija.txt");
	if (datoteka1.is_open())
	{
		datoteka1 >> i;
		datoteka1.close();
	}
	if (!i)
	{
		int pomocna = 0;
		std::cout << "Da li zelite instalirati aplikaciju 1/0?" << std::endl;
		std::cin >> pomocna;//Da ili ne=>Onaj blok=>Isidora
		if (pomocna == 0)
		{
			std::cout << "Dovidjenja, prijatno!" << std::endl;
			return false;
		}
		else
			instalacija();
		std::ofstream fajl;
		fajl.open("instalacija.txt");
		if (fajl.is_open())
		{
			fajl << 1;
			fajl.close();
		}
	}
	std::ifstream datoteka;
	datoteka.open("instalacija.txt");
	if (datoteka.is_open())
	{
		datoteka >> i;
		datoteka.close();
	}
	if (i)
		return true;
	else
		return false;
}
void deinstalacija()
{
	std::ofstream datoteka;
	datoteka.open("instalacija.txt");
	{
		datoteka << 0;
		datoteka.close();
	}
}