#include "CetvrtaIgra.h"
#include <vector>
#include <time.h>
#include <fstream>
#include <cmath>
#include <windows.h>

using namespace std;

void Pisi(string poruka, bool GornjiDio , bool DonjiDio )//gornji i donji dio se koriste radi razgranicavanja segmenata koje zelimo naglasiti
{
	if (GornjiDio)
	{
		cout << "o=================================o" << endl;
		cout << "|";
	}
	else cout << "|";
	bool pocetak = true;
	for (int i = poruka.length(); i < 33; i++)  //33 zbog sirine, petlja se koristi u svrhu centriranja poruke
	{
		if (pocetak)
			poruka = " " + poruka;// u c++ je dozvoljen ovaj nacin manipulisanja sa stringovima 
		else
			poruka = poruka + " ";
		pocetak = !pocetak;
	}
	cout << poruka;
	if (DonjiDio)
	{
		cout << "|" << endl;
		cout << "o=================================o" << endl;
	}
	else  cout << "|" << endl;;
}
void Crtaj(int brojPokusaja )//za crtanje "covjeka" nakon pogresnih pokusaja
{
	if (brojPokusaja >= 1)
		Pisi("|", false, false);
	else
		Pisi("", false, false);// poziva se ispisivanje praznog prostora zbog konstantnog odrzavanja izlaza,tj. njegove forme
	if (brojPokusaja >= 2)
		Pisi("|", false, false);
	else
		Pisi("", false, false);
	if (brojPokusaja >= 3)
		Pisi("O", false, false);
	else
		Pisi("", false, false);
	if (brojPokusaja == 4)// sastoji se iz tri dijela stoga moramo specifikovati broj pokusaja
		Pisi("/  ", false, false);
	if (brojPokusaja == 5)
		Pisi("/| ", false, false);
	if (brojPokusaja >= 6)
		Pisi("/|\\", false, false);
	else Pisi("", false, false);
	if (brojPokusaja >= 7)
		Pisi("|", false, false);
	else
		Pisi("", false, false);
	if (brojPokusaja == 8)
		Pisi("/  ", false, false);
	if (brojPokusaja >= 9)
		Pisi("/ \\", false, false);
	else
		Pisi("", false, false);
}
void prolazakKrozSlova(string pokusaj, char od, char doKraja)//ispisuje slova dostupna za upotrebu
{
	string pom;
	for (char i = od; i <= doKraja; i++)
	{
		if (pokusaj.find(i) == string::npos)// vraca npos u slucaju da ne pronadje trazeni karakter i
		{
			if (i != 'Q' && i != 'X' && i != 'Y' && i != 'W')
			{
				pom += i;
				pom += " ";
			}
		}
		else
			pom += "  ";
	}
	Pisi(pom, false, false);
}
void PisiDostupnaSlova(string pokusaj)
{
	Pisi("Dostupna Slova");
	prolazakKrozSlova(pokusaj, 'A', 'L');//A K  L V
	prolazakKrozSlova(pokusaj, 'M', 'Z');
}
bool pogadjajSlova(string rijec, string pokusaj)
{
	bool pogodak = true;
	string s;
	for (int i = 0; i < rijec.length(); i++)
	{
		if (pokusaj.find(rijec[i]) == string::npos)
		{
			pogodak = false;
			s += "_ ";
		}
		else
		{
			s += rijec[i];
			s += " ";
		}
	}
	Pisi(s, false);
	return pogodak;
}
string ucitajNasumicnuRijec(string putanja)
{
	string rijec;
	string tip;
	vector<string> vs;//koristimo ga za smjestanje rijeci iz fajla
	ifstream citanje;
	citanje.open(putanja);//funkcija za otvaranje txt fajla
	if (citanje.is_open())
	{
		while (citanje >> rijec >> tip)// ucitavanje rijeci iz fajla
			vs.push_back(rijec);
		int slucRed = rand() % vs.size();//za nasumican odabir rijeci iz datoteke
		rijec = vs.at(slucRed);
		citanje.close();
	}
	return rijec;
}
int ostaloPokusaja(string rijec, string pokusaj)
{
	int greske = 0;
	for (int i = 0; i < pokusaj.length(); i++)
	{
		if (rijec.find(pokusaj[i]) == string::npos)
			greske++;
	}
	return greske;
}
string ucitajTip(string putanja, string rijec)
{
	string rijec1;
	string tip, tip1;
	ifstream citanje;
	citanje.open(putanja);
	if (citanje.is_open())
	{
		while (citanje >> rijec1 >> tip)
			if (rijec1 == rijec)
				tip1 = tip;
		citanje.close();
	}
	return tip1;
}
void vjesala(int& bodovi)
{
	srand(time(0));//da bi se trazena rijec uvijek nasumicno nasla
	string rijecZaPogoditi;
	string pokusaji;
	rijecZaPogoditi = ucitajNasumicnuRijec("rijeciZaPogadjanje.txt");
	string tip = ucitajTip("rijeciZaPogadjanje.txt", rijecZaPogoditi);
	int brojPokusaja = 0;
	bool pogodak = false;
	int j = 0;
	do
	{
		system("cls");
		cout << "Tip rijeci: " << tip << endl;
		cout << "Broj pokusaja: " << j++ << endl;
		cout << "Duzina rijeci: " << rijecZaPogoditi.length() << endl << endl;
		Pisi("Igra vjesala");
		Crtaj(brojPokusaja);
		PisiDostupnaSlova(pokusaji);
		Pisi(" Trazena rijec");
		pogodak = pogadjajSlova(rijecZaPogoditi, pokusaji);
		if (pogodak)
			break;
		char slovo;
		cout << "Unesi slovo:"; cin >> slovo;
		if (pokusaji.find(slovo) == string::npos && slovo < 'a' && slovo >= 'A')//da li se unose nova slova
			pokusaji += slovo;
		else if (slovo >= 'a' && slovo < 'z')
		{
			cout << "Unesite veliko slovo" << endl;; Sleep(2000);
			j--;
		}
		else if (slovo > 'z' || slovo < 'A')
		{
			cout << "Unesite karakter slova!" << endl; Sleep(2000);
			j--;
		}
		else
		{
			cout << "Unesite slovo koje do sada niste!" << endl; Sleep(2000);
			j--;
		}
		brojPokusaja = ostaloPokusaja(rijecZaPogoditi, pokusaji);

	} while (brojPokusaja < 9);
	system("cls");
	Pisi("Igra vjesala");
	Crtaj(brojPokusaja);
	Pisi("", false, true);
	if (pogodak)
	{
		Pisi("Pobijedili ste.");
		bodovi += 50;
	}
	else
	{
		cout << "Trazena rijec je:" << endl;
		Pisi(rijecZaPogoditi);
		bodovi -= 20;
	}

	getchar();
}