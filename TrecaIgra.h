#pragma once
#include "Korisnik.h"
#include <iostream>
#include <cstdlib>  // sadrzi random funkciju - stalno vraca isti broj 
#include <time.h>   // zato treba i ova koja ima srand
#include <string>  // sl sve tri bibl su zbog š,č,ć,.. valjdaa
#include <cstdio>
#include <Windows.h>
#define sleep(x) Sleep(x)
class LOTO
{
public:
	int lotoBrojevi[20];
	int odigraniBrojevi[7];
};
int isTheSame(int [], int );
bool funkcijaZaVaranje(int* , int [], int , int , int []);
int brojPogodakaFunkcija(int [], int []);
int sumaBodova(int );
void sortirajNiz(int* , int );
void ispisiRezultat(int [], int [], int,Korisnik );
void lotoIgra(int* , int* , LOTO*,Korisnik );