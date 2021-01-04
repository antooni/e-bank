#pragma once
#include <iostream>
#include <fstream>

#include "operacja.h"

using namespace std;

class Baza {
	// nazwy plikow
public:
	Baza();
	Operacja odczyt(Operacja);
	Operacja zapis(Operacja);
};