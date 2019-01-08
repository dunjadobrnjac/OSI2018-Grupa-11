#pragma once
#include <string>
#include <iostream>

std::string Vrijeme(void);
void upisiUTxtFajl(int, int, std::string);
void SelectionSort(struct Stats*, int, int);
void smjestiNaPravoMjesto(int);
void upisiUTxtFajlW(int, int, std::string, int);
void ispisStatistike(int);
void pisiUCSV();

struct Stats
{
	int brojIgre;
	std::string datum;
	int brojBodova;
};