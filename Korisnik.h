#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Korisnik
{
public:
	Korisnik(int = 10, int = 0);

	friend std::istream& operator>>(std::istream&, Korisnik&);
	friend std::ostream& operator<<(std::ostream&, const Korisnik&);
	const char* getIme()const;
    const  int& getBrUlaza()const;
	bool dajKljuc(int,int);
	bool provjeraKljuca(int);
	void upisiBodove()const;
	void ispisiBodove()const;
	void ucitajBodove();
	void ucitajKljuc(int);
	void upisKljuca(int,int);
	void otkaziIgru(int);
	int brojBodova;
	int brojUlozenihBodova;
private:
	char* ime;
	void sacuvajIme();
	static int brUlaza;
};

