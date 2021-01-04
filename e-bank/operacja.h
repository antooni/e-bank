#pragma once
#include <iostream>


using namespace std; 

class Do_wykonania
{
	string nadawca;
	string adresat;
	int suma;
	// Kontakt;

public:
	Do_wykonania();
};

class Dane
{
	int saldo;
	// Kontakt
	// Historia
	// Kursy
	Do_wykonania* do_wykonania;

public:
	Dane();
};

class Operacja
{
	string typ;
	string typ_operacji;
	string token;
	int kod_bledu;
	Dane* dane;

public:
	Operacja();
};
