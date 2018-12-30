#include <iostream>
#include "Statistika.h"
#include <Windows.h>
#include <wchar.h>
#include <sstream>
#include <fstream>

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
		Temp << time.wDay << "." << time.wMonth << "." << time.wYear << ".   " << time.wHour << ":" << time.wMinute << ":" << time.wSecond;
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
void BubbleSort(Stats niz[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int max = i;
		for (j = i; j < n; j++)
			if (niz[max].brojBodova < niz[j].brojBodova)
				max = j;
		  if(max!=i)
			{
				Stats pom = niz[i];
				niz[i] = niz[max];
				niz[max] = pom;
			}
	}
}
void PisiUCSVFajl(Stats niz[])
{
	std::ofstream Pisi;
	Pisi.open("StatistikaCsv.csv");
	if (Pisi.is_open())
	{
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (niz[j].brojIgre == i)
				{
					Pisi << niz[j].brojIgre << " . Igra:" << niz[j].datum << " ----- " << niz[j].brojBodova << "\n";
				}
			}
		}
		Pisi.close();
	}
}
void UmetniTrenutneBodove(int bod, Stats niz[], int brojIgre)
{
	bool k = true;
	int i;
	k = 1;
	while (k)
	{
		i = 9;
		if (niz[i].brojIgre == brojIgre)
		{
			if (niz[i].brojBodova < bod)
			{
				niz[i].brojBodova = bod;
				niz[i].brojIgre = brojIgre;
				niz[i].datum = Vrijeme();
				k = false;
			}
			if (i == 0)
				k = false;
		}
		i--;
	}
}
void PisiUStatistiku(Stats niz[])
{
	std::ofstream Pisi;
	Pisi.open("Statistika.txt");
	if (Pisi.is_open())
	{
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (niz[j].brojIgre == i)
				{
					Pisi << niz[j].brojIgre << "\n";
					Pisi << niz[j].datum << "\n";
					Pisi << niz[j].brojBodova << "\n";
				}
			}
		}
		Pisi.close();
	}
}
void IspisiStatistiku(Stats niz[])
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (niz[j].brojIgre == i)
			{
				std::cout<<"\n" << niz[j].brojIgre << ". Igra: " << niz[j].datum << " ----- " << niz[j].brojBodova << std::endl;

			}
		}
	}
}
void statistika(int bodovi, int brojIgre)
{

	Stats niz[10];
	std::ifstream MyDat;
	Vrijeme();
	MyDat.open("Statistika.txt");
	if (MyDat.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			std::string data;
			std::getline(MyDat, data);
			std::istringstream iss(data);
			iss >> niz[i].brojIgre;
			std::getline(MyDat, niz[i].datum);
			std::string data2;
			std::getline(MyDat, data2);
			std::istringstream iss2(data2);
			iss2 >> niz[i].brojBodova;
			std::cout << niz[i].brojIgre << std::endl << niz[i].datum << std::endl << niz[i].brojBodova;
		}
		MyDat.close();
	}
	BubbleSort(niz, 10);
	//UmetniTrenutneBodove(bodovi, niz, brojIgre); // POZVATI AKO JE STATISTIKA PUNA MIJENJA NAJMANJI BROJ BODOVA ZA DATU IGRU
	BubbleSort(niz, 10);
	IspisiStatistiku(niz);
	PisiUStatistiku(niz);
	PisiUCSVFajl(niz);
}
void upisiUDat(int igra, int bodovi)
{
	std::ofstream Pisi;
	Pisi.open("Statistika.txt");
	if (Pisi.is_open())
	{
		std::string datum = Vrijeme();
		Pisi << igra << "\n";
		Pisi << datum << "\n";
		Pisi << bodovi << "\n";
		Pisi.close();
	}
}