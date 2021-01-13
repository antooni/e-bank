#pragma once
#include <iostream>
#include <vector>
#include "dodatkowe.h"
#include "operacja.h"

using namespace std; 

// mozna sprobowac poukrywa� pola zeby nie byly public
// i pozaprzyjazniac klasy

class Do_wykonania
{
public:
	Historia historia;
	Kontakty kontakty;
	Saldo saldo;
	double suma = 0;
	string odbiorca;


	Do_wykonania();
};

class Dane
{
public:
	vector <Historia> historia;
	vector <Kontakty> kontakty;
	Saldo* saldo;
	Kurs* kurs;
	Do_wykonania* do_wykonania;
	Uzytkownik* uzytkownik;

	string znajdz_numer(string);
	void wypisz_saldo();
	void wypisz_kontakty();
	void wypisz_historia();
	void wypisz_kurs();
	bool sprawdz_kwote(double suma, string waluta);
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
	Do_wykonania* do_wykonania;
	Operacja();
};


