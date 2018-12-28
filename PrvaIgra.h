#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>  // sadrzi random funkciju - stalno vraca isti broj 
#include <time.h>   // zato treba i ova koja ima srand
#include <string>  // sl sve tri biblioteke su zbog š,č,đ,.. valjdaa
#include <cstdio>
#include <Windows.h>


void igrajPrvuIgru(int&);
int prvaIgraPrava(int &, int&);
int prvaIgraVaranje(int &,int&);