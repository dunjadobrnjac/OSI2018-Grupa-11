#include "Statistikka.h"
#include <Windows.h>
#include <wchar.h>
#include <sstream>
#include <fstream>
#include <string>
#include "TrecaIgra.h"



std::string Vrijeme()
{
	std::string TrenutniDatum;
	SYSTEMTIME time;
	GetLocalTime(&time);
	//(L"Time: %02d:%02d:%02d\n", time.wHour, time.wMinute, time.wSecond);
	std::ofstream Temp;
	Temp.open("Temp.txt");
	if (Temp.is_open())
	{
		if (time.wDay < 10)Temp << "0";
		Temp << time.wDay << ".";
		if (time.wMonth < 10)Temp << "0";
		Temp << time.wMonth << "." << time.wYear << ".   ";
		if (time.wHour < 10)Temp << "0";
		Temp << time.wHour << ":";
		if (time.wMinute < 10)Temp << "0";
		Temp << time.wMinute << ":";
		if (time.wSecond < 10)Temp << "0";
		Temp << time.wSecond;
		Temp.close();
	}
	std::ifstream Tmp;
	Tmp.open("Temp.txt");
	if (Tmp.is_open())
	{
		std::getline(Tmp, TrenutniDatum);
		Temp.close();
	}
	return TrenutniDatum;
}

void upisiUTxtFajl(int igra, int bodovi, std::string vr)
{
	
	Stats s = {igra, vr, bodovi};
	std::ofstream Pisi;
	if(igra==1)
		Pisi.open("StatistikaZaPrvuIgru.txt", std::ios_base::app);
	else if(igra==2)
		Pisi.open("StatistikaZaDruguIgru.txt", std::ios_base::app);
	else if(igra==3)
		Pisi.open("StatistikaZaTrecuIgru.txt", std::ios_base::app);
	else if(igra==4)
		Pisi.open("StatistikaZaCetvrtuIgru.txt", std::ios_base::app);
	if (Pisi.is_open())
	{
		Pisi << s.brojIgre << " ";
		Pisi << s.datum << " ";
		Pisi << s.brojBodova <<'b'<< std::endl;
		//Pisi << s;
		Pisi.close();
	}
	smjestiNaPravoMjesto(igra);
}

/*std::ostream& operator<<(std::ostream& izlaz, const Stats& s)
{
	izlaz << s.brojIgre << " ";
	izlaz << s.datum << " ";
	izlaz << s.brojBodova << 'b' << std::endl;
}*/

void smjestiNaPravoMjesto(int igra)
{
	std::ifstream datoteka1;
	std::string prazanString = "";
	int brojLinija = 0;
	if (igra == 1)
		datoteka1.open("StatistikaZaPrvuIgru.txt");
	else if (igra == 2)
		datoteka1.open("StatistikaZaDruguIgru.txt");
	else if (igra == 3)
		datoteka1.open("StatistikaZaTrecuIgru.txt");
	else if (igra == 4)
		datoteka1.open("StatistikaZaCetvrtuIgru.txt");
	if (datoteka1.is_open())
	{
		while (getline(datoteka1, prazanString))
			brojLinija++;
		datoteka1.close();
	}
	Stats* niz = new Stats[brojLinija];
	//std::cout << brojLinija << std::endl;
	for (int i = 0; i < brojLinija; i++)
	{
		niz[i].brojBodova = 0;
		niz[i].brojIgre = 0;
		niz[i].datum = "";
	}
	std::string nekiString;
	std::ifstream datoteka;
	int i = 0;
	if (igra == 1)
		datoteka.open("StatistikaZaPrvuIgru.txt");
	else if (igra == 2)
		datoteka.open("StatistikaZaDruguIgru.txt");
	else if (igra == 3)
		datoteka.open("StatistikaZaTrecuIgru.txt");
	else if (igra == 4)
		datoteka.open("StatistikaZaCetvrtuIgru.txt");
	if (datoteka.is_open())
	{
		for (int i = 0; i < brojLinija;++i)
		{
			//datoteka >> niz[i].brojIgre >> niz[i].datum >> niz[i].brojBodova;
			getline(datoteka, nekiString);
			std::string noviString = "";
			niz[i].brojIgre = nekiString[0] == '1' ? 1 : (nekiString[0] == '2' ? 2 : (nekiString[0] == '3' ? 3 : (nekiString[0] == '4' ? 4 : 5)));
			for (int j = 2; j < 24;j++)
				niz[i].datum += nekiString[j];
			int j = 25;
			while (nekiString.at(j) != 'b')
			{
				noviString += nekiString[j];
				j++;
			}
			noviString.empty();
			niz[i].brojBodova = std::stoi(noviString);
			nekiString.empty();
		}
		datoteka.close();
	}
	SelectionSort(niz, brojLinija, igra);
	/*for (int i = 0; i < brojLinija; i++)
		upisiUTxtFajl(niz[i].brojIgre, niz[i].brojBodova, niz[i].datum);*/
	/*for (int i = 0; i < brojLinija; ++i)
		std::cout << niz[i].brojIgre << " " << niz[i].datum << " " << niz[i].brojBodova << std::endl;*/
}

void SelectionSort(Stats* niz, int n, int brojIgre)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int max = i;
		for (j = i; j < n; j++)
			if (niz[max].brojBodova < niz[j].brojBodova)
				max = j;
		if (max != i)
		{
			Stats pom = niz[i];
			niz[i] = niz[max];
			niz[max] = pom;
		}
	}
	std::ofstream datoteka;
	if (brojIgre == 1)
		datoteka.open("StatistikaZaPrvuIgru.txt");
	else if (brojIgre == 2)
		datoteka.open("StatistikaZaDruguIgru.txt");
	else if (brojIgre == 3)
		datoteka.open("StatistikaZaTrecuIgru.txt");
	else if (brojIgre == 4)
		datoteka.open("StatistikaZaCetvrtuIgru.txt");
	if (datoteka.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			Stats s = { niz[i].brojIgre, niz[i].datum, niz[i].brojBodova };
			datoteka << s.brojIgre << " ";
			datoteka << s.datum << " ";
			datoteka << s.brojBodova << 'b' << std::endl;
		}
		datoteka.close();
	}
}

void ispisStatistike(int brojIgre)
{
	system("cls");
	std::string prazanString;
	int brojLinija = 0;
	std::ifstream datoteka1;
	if (brojIgre == 1)
		datoteka1.open("StatistikaZaPrvuIgru.txt");
	else if (brojIgre == 2)
		datoteka1.open("StatistikaZaDruguIgru.txt");
	else if (brojIgre == 3)
		datoteka1.open("StatistikaZaTrecuIgru.txt");
	else if (brojIgre == 4)
		datoteka1.open("StatistikaZaCetvrtuIgru.txt");
	if (datoteka1.is_open())
	{
		while (getline(datoteka1, prazanString))
			brojLinija++;
		datoteka1.close();
	}
	std::cout << "BROJ LINIJA JE" << brojLinija << std::endl;
	if (brojLinija > 10)
		brojLinija = 10;
	std::ifstream datoteka;
	if (brojIgre == 1)
	{
		datoteka.open("StatistikaZaPrvuIgru.txt");
		std::cout << "STATISTIKA ZA PRVU IGRU:" << std::endl << std::endl;
	}
	else if (brojIgre == 2)
	{
		datoteka.open("StatistikaZaDruguIgru.txt");
		std::cout << "STATISTIKA ZA DRUGU IGRU:" << std::endl << std::endl;
	}
	else if (brojIgre == 3)
	{
		datoteka.open("StatistikaZaTrecuIgru.txt");
		std::cout << u8"STATISTIKA ZA TREĆU IGRU:" << std::endl << std::endl;
	}
	else if (brojIgre == 4)
	{
		datoteka.open("StatistikaZaCetvrtuIgru.txt");
		std::cout << u8"STATISTIKA ZA ČETVRTU IGRU:" << std::endl << std::endl;
	}
	std::string nekiString = "";
	if (brojLinija == 0)
	{
		std::cout << u8"JOŠ UVIJEK NISTE IGRALI OVU IGRU"<<std::endl;
		Sleep(7000);
		return;
	}
	Stats *niz = new Stats[brojLinija];
	if (datoteka.is_open())
	{
		for (int i = 0; i < brojLinija;++i)
		{
			//datoteka >> niz[i].brojIgre >> niz[i].datum >> niz[i].brojBodova;
			getline(datoteka, nekiString);
			std::string noviString = "";
			niz[i].brojIgre = nekiString[0] == '1' ? 1 : (nekiString[0] == '2' ? 2 : (nekiString[0] == '3' ? 3 : (nekiString[0] == '4' ? 4 : 5)));
			for (int j = 2; j < 24;j++)
				niz[i].datum += nekiString[j];
			int j = 25;
			while (nekiString.at(j) != 'b')
			{
				noviString += nekiString[j];
				j++;
			}
			noviString.empty();
			niz[i].brojBodova = std::stoi(noviString);
			nekiString.empty();
			if(i<9)
				std::cout <<" "<< i+1 << ".-->  " << niz[i].brojIgre << ". igra  " << niz[i].datum << "  " << niz[i].brojBodova << std::endl;
			else
				std::cout << i + 1 << ".-->  " << niz[i].brojIgre << ". igra  " << niz[i].datum << "  " << niz[i].brojBodova << std::endl;
		}
	}
	Sleep(7000);
}

void pisiUCSV()
{
	std::string string = "CSV";
	string += "-->";
	string += Vrijeme();
	string += ".csv";
	std::cout << string << std::endl;
	Sleep(2000);
	std::ofstream datoteka;
	datoteka.open("StatistikaCsv.csv");
	if (datoteka.is_open())
	{
		for (int brojIgre = 1;brojIgre < 5; brojIgre++)
		{
			std::string prazanString;
			int brojLinija = 0;
			std::ifstream datoteka1;
			if (brojIgre == 1)
				datoteka1.open("StatistikaZaPrvuIgru.txt");
			else if (brojIgre == 2)
				datoteka1.open("StatistikaZaDruguIgru.txt");
			else if (brojIgre == 3)
				datoteka1.open("StatistikaZaTrecuIgru.txt");
			else if (brojIgre == 4)
				datoteka1.open("StatistikaZaCetvrtuIgru.txt");
			if (datoteka1.is_open())
			{
				while (getline(datoteka1, prazanString))
					brojLinija++;
				datoteka1.close();
			}
			//std::cout << "Broj linija" << brojLinija << std::endl;
			//system("pause");
			std::ifstream datoteka2;
			if (brojLinija > 10)
				brojLinija = 10;
			if (brojIgre == 1)
			{
				datoteka2.open("StatistikaZaPrvuIgru.txt");
				datoteka << "PRVA IGRA - TOP 10: " << std::endl << std::endl;
			}
			else if (brojIgre == 2)
			{
				datoteka2.open("StatistikaZaDruguIgru.txt");
				datoteka << "DRUGA IGRA - TOP 10: " << std::endl << std::endl;
			}
			else if (brojIgre == 3)
			{
				datoteka2.open("StatistikaZaTrecuIgru.txt");
				datoteka << u8"TREĆA IGRA - TOP 10:" << std::endl << std::endl;
			}
			else if (brojIgre == 4)
			{
				datoteka2.open("StatistikaZaCetvrtuIgru.txt");
				datoteka << u8"ČETVRTA IGRA - TOP 10: " << std::endl << std::endl;
			}
			std::string nekiString = "";
			if (brojLinija == 0)
			{
				datoteka << u8"JOŠ UVIJEK NISTE IGRALI OVU IGRU" << std::endl << std::endl;

			}
			else
			{ 
				Stats *niz = new Stats[brojLinija];
				datoteka << "Broj:,Redni broj igre,Vrijeme igranja,Broj bodova"<<std::endl;
				if (datoteka2.is_open())
				{
					for (int i = 0; i < brojLinija;++i)
					{
						//datoteka >> niz[i].brojIgre >> niz[i].datum >> niz[i].brojBodova;
						getline(datoteka2, nekiString);
						std::string noviString = "";
						niz[i].brojIgre = nekiString[0] == '1' ? 1 : (nekiString[0] == '2' ? 2 : (nekiString[0] == '3' ? 3 : (nekiString[0] == '4' ? 4 : 5)));
						for (int j = 2; j < 24;j++)
							niz[i].datum += nekiString[j];
						int j = 25;
						while (nekiString.at(j) != 'b')
						{
							noviString += nekiString[j];
							j++;
						}
						noviString.empty();
						niz[i].brojBodova = std::stoi(noviString);
						nekiString.empty();
						/*if (i < 9)
							std::cout << " " << i + 1 << ".-->  " << niz[i].brojIgre << ". igra  " << niz[i].datum << "  " << niz[i].brojBodova << std::endl;
						else
							std::cout << i + 1 << ".-->  " << niz[i].brojIgre << ". igra  " << niz[i].datum << "  " << niz[i].brojBodova << std::endl;*/
						int a = i+1;
						noviString = std::to_string(a);
						noviString += ".,";
						noviString += std::to_string(niz[i].brojIgre);
						noviString += ".igra,";
						noviString += niz[i].datum;
						noviString += ",";
						noviString += std::to_string(niz[i].brojBodova);
						//noviString += " bodova";
						std::cout << "noviString: " << noviString << std::endl;

						datoteka << noviString << std::endl;
					}
					Sleep(10000);
					datoteka << std::endl << std::endl << std::endl;
				}
			}
		}

	}

}
