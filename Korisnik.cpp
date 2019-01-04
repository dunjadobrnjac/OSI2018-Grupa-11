#include "Korisnik.h"
#include <fstream>
#include <ctype.h>
#include <time.h>
#include <Windows.h>

int Korisnik::brUlaza = 0;

Korisnik::Korisnik(int br1, int br2)
{
	brojBodova = br1;
	brojUlozenihBodova = 0;
}

Korisnik::~Korisnik()
{
	delete[] ime;
	ime = nullptr;
}

const char* Korisnik::getIme() const
{
	char *s = new char[20];
	std::ifstream ulaz;
	ulaz.open("ime.txt");
	if (ulaz.is_open())
	{
		ulaz >> s;
	}
	return s;
}

const int & Korisnik::getBrUlaza()const
{
	std::ifstream br;
	br.open("brojUlaza.txt");
	if (br.is_open())
	{
		br >> brUlaza;
		br.close();
	}
	return brUlaza;
}

bool Korisnik::dajKljuc(int trajanje,int igra) 
{
	char *s=new char[20];
	std::ifstream kljucevi;
	int i;//za dobavljanje kljuca koji do sada nije vracen,a da je istog trajanja
	if (trajanje == 1)
	{
		kljucevi.open("kljucevi1h.txt");
		i = 0;
	}
	else if (trajanje == 2)
	{
		kljucevi.open("kljucevi1dan.txt");
		i = 1;
	}
	else if (trajanje == 3)
	{
		kljucevi.open("kljucevi7dana.txt");
		i = 2;
	}
	else
	{
		kljucevi.open("kljucZaCetvrtu.txt");
		i = 3;
	}
	if (kljucevi.is_open())
	{
		std::ifstream red;
		red.open("redKljucevaPoTrajanjima.txt");
		int r[4];
		red >> r[0] >> r[1] >> r[2] >> r[3];
		for(int j=0;j<=r[i];j++)
		 kljucevi >> s;
		r[i]++;
		red.close();
		std::ofstream red1;
		red1.open("redKljucevaPoTrajanjima.txt"); red1 << r[0] << "\n" << r[1] << "\n" << r[2] << "\n" << r[3];
		red1.close();
		std::cout << s;
		std::cout << std::endl << "Zapisite na papir da ne biste zaboravili,imate 15s !" << std::endl;
		Sleep(15000);
		//system("pause");
	}
	system("cls");
	std::cout << "Unesite trazeni kljuc: ";
	char s1[20];
	std::cin >> s1;
	if (strcmp(s1, s) == 0)
	{
		upisKljuca(igra,trajanje);
		return true;
	}
	return false;
}

std::istream & operator>>(std::istream &input, Korisnik &k)
{
	char s[20];
	std::cout << "Unesite ime : "; input >> s;
	k.ime = new char[strlen(s) + 1];
	strcpy(k.ime, s);
	k.ime[strlen(s)] = 0;
	k.sacuvajIme();
	k.brUlaza++;
	std::ofstream br;
	br.open("brojUlaza.txt");
	if (br.is_open())
	{
		br << k.brUlaza;
		br.close();
	}
	return input;
}

void Korisnik::sacuvajIme()
{
	std::ofstream izlaz;
	izlaz.open("ime.txt");
	if (izlaz.is_open())
	{
		izlaz << ime;
		izlaz.close();
	}
}

void Korisnik::upisiBodove()const
{
	std::ofstream upis;
	upis.open("bodovi.txt");
	if (upis.is_open())
	{
		upis << brojBodova << " " << brojUlozenihBodova;
		upis.close();
	}
}

void Korisnik::ispisiBodove() const
{
	std::cout << u8"Vaš trenutni broj bodova je : "<< brojBodova << u8"\nVaš uloženi broj bodova je : " << brojUlozenihBodova << std::endl;
}

void Korisnik::ucitajBodove()
{
	std::ifstream unesi;
	unesi.open("bodovi.txt");
	if (unesi.is_open())
	{
		unesi >> brojBodova >> brojUlozenihBodova;
		unesi.close();
	}
}



std::ostream & operator<<(std::ostream &output, const Korisnik &k)
{
	output << "Pozdrav " << k.ime << " !" << std::endl;
	return output;
}

void Korisnik::ucitajKljuc(int igra)
{
	/*int igra;
	std::cout << "Za koju igru zelite kljuc: "; std::cin >> igra;*/
	int t;
	std::cout << "Unesite broj za trajanje kljuca: 1-1h  2-1dan 3-7dana :"; std::cin >> t;
	if (dajKljuc(t, igra))
	{
		std::cout << "Mozete igrati " << igra << ". igru ";
		switch (t)
		{
		case 1:
			std::cout << "narednih sat vremena." << std::endl;
			break;
		case 2:
			std::cout << "narednih 24h." << std::endl;
			break;
		case 3:
			std::cout << "narednih 7 dana." << std::endl;
			break;
		case 4:
			std::cout << "neograniceno." << std::endl;
			break;
		}
	}
	else
		std::cout << "Nemate pristup " << igra << ". igri, kljuc nije validan." << std::endl;
}

void Korisnik::upisKljuca(int igra,int t)
{
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::ofstream upis;
	switch (igra)
	{
	case 1:
		upis.open("trajanjePrvaIgra.txt");
		break;
	case 2:
		upis.open("trajanjeDrugaIgra.txt");
		break;
	case 3:
		upis.open("trajanjeTrecaIgra.txt");
		break;
	case 4:
		upis.open("trajanjeCetvrtaIgra.txt");
		break;
	}
	if (upis.is_open())
	{
		upis << t << "\n";
		upis << rawtime;
		upis.close();
	}
}

bool Korisnik::provjeraKljuca(int igra)
{
	std::ifstream unos;
	double sek;
	switch (igra)
	{
	case 1:
		unos.open("trajanjePrvaIgra.txt");
		break;
	case 2:
		unos.open("trajanjeDrugaIgra.txt");
		break;
	case 3:
		unos.open("trajanjeTrecaIgra.txt");
		break;
	case 4:
		unos.open("trajanjeCetvrtaIgra.txt");
		break;
	}
	if (unos.is_open())
	{
		int trajanje;
		unos >> trajanje;
		if (igra == 4 && trajanje == 4)
			return true;
		if (trajanje == 0)
			return false;
		switch (trajanje)
		{
		case 1:
			sek = 3600;
			break;
		case 2:
			sek = 24 * 3600;
			break;
		case 3:
			sek = 7 * 24 * 3600;
			break;
		default:
			std::cout << "Greska u unosu trajanja kljuca!" << std::endl;
		}
		//std::cout << trajanje << " " << sek;
		time_t sad,unijeto;
		unos >> unijeto;
		time(&sad);
		if (difftime(sad,unijeto) < sek)
		{
			//std::cout << "Razlika u sekundama je " << difftime(sad, unijeto)<<"\n";
			return true;
		}
		unos.close();
		return false;
	}
}