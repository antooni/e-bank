#pragma once
#include <iostream>
#include <vector>
#include "dodatkowe.h"

using namespace std; 

// mozna sprobowac poukrywaæ pola zeby nie byly public
// i pozaprzyjazniac klasy

class Do_wykonania
{
public:
	string nadawca;
	string adresat;
	double suma;
	// Kontakt;


	Do_wykonania();
};

class Dane
{
public:
	vector <Historia> historia;
	vector <Kontakty> kontakty;
	Saldo* saldo;
	Kurs kursy;
	
	Do_wykonania* do_wykonania;

	void wypisz_saldo();
	Dane();
};

class Operacja
{
public:
	string typ;
	string typ_operacji;
	string token;
	int kod_bledu;
	Dane* dane;
	Operacja();
};
