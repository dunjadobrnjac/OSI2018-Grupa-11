#pragma once
#include <string>
#include <iostream>
void statistika(int, int, bool);
void IspisiStatistiku(struct Stats,int);
void PisiUStatistiku(struct Stats);
void UmetniTrenutneBodove(int, struct Stats, int);
void PisiUCSVFajl(struct Stats);
void SelectionSort(struct Stats, int);
std::string Vrijeme(void);
void upisiUDat(int,int,std::string);


struct Stats {
	int brojIgre;
	std::string datum;
	int brojBodova;
};