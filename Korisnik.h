#pragma once
#include <iostream>

class Korisnik
{
public:
	Korisnik(int =10,int =0);
	~Korisnik();
	friend std::istream& operator>>(std::istream&, Korisnik&);
	friend std::ostream& operator<<(std::ostream&, const Korisnik&);
	const char* getIme()const;
    const  int& getBrUlaza()const;
	bool dajKljuc(int,int);
	void upisiBodove()const;
	void ispisiBodove()const;
	void ucitajBodove();
	void ucitajKljuc(int);
	void upisKljuca(int,int);
	bool provjeraKljuca(int);
	int brojBodova;
	int brojUlozenihBodova;
private:
	char* ime;
	void sacuvajIme();
	static int brUlaza;
};

