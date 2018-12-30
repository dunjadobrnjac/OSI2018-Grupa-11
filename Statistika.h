#pragma once
#include <string>
#include <iostream>
void statistika(int, int);
void IspisiStatistiku(struct Stats);
void PisiUStatistiku(struct Stats);
void UmetniTrenutneBodove(int, struct Stats, int);
void PisiUCSVFajl(struct Stats);
void BubbleSort(struct Stats, int);
std::string Vrijeme(void);
void upisiUDat(int, int);

struct Stats {
	int brojIgre;
	std::string datum;
	int brojBodova;
};