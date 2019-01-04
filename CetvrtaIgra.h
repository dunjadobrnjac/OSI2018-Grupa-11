#pragma once
#include "Korisnik.h"
#include <string>
#include <iostream>


void Pisi(std::string, bool = true, bool = true);
void Crtaj(int = 0);
void prolazakKrozSlova(std::string, char, char);
void PisiDostupnaSlova(std::string);
bool pogadjajSlova(std::string,std::string);
std::string ucitajNasumicnuRijec(std::string);
int ostaloPokusaja(std::string, std::string);
std::string ucitajTip(std::string,std::string);
void vjesala(int&,Korisnik);