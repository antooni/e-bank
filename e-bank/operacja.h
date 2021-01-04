#pragma once
#include <iostream>


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
	double saldo;
	// Kontakt
	// Historia
	// Kursy
	Do_wykonania* do_wykonania;


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
