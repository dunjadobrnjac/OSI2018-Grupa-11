#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>  // sadrzi random funkciju - stalno vraca isti broj 
#include <time.h>   // zato treba i ova koja ima srand
#include <string>  // sl sve tri biblioteke su zbog š,č,đ,.. valjdaa
#include <cstdio>
#include <Windows.h>


static int osvojeniBodovi = 10;
void igrajPrvuIgru();
int prvaIgraPrava(int &brojIgranja);
int prvaIgraVaranje(int &brojIgranja);