#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "operacja.h"
#include "dodatkowe.h"



using namespace std;
			//klasa obsugujaca baze danych
class Baza {
public:
	Baza();
	Operacja odczyt(Operacja);
	Operacja zapis(Operacja);
	Operacja wczytaj_stopka(Operacja);
};