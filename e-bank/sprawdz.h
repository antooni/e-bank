#pragma once

#include<iostream>

using namespace std;


class Operacja {
	Typ_operacji typ_operacji;
	Dane dane;
	int token_sesji;
	Data data_operacji;
	Blad blad;
};

class Dane {
	string typ_danych;
	double wartosc;
};

class Typ_operacji {
	string typ_operacji;
public:
	bool sprawdz_czy_wykonaj(string typ_operacji);
};

class Blad {
	int kod_bledu;
	string informacje;
};

class Sprawdz {
	Historia his;
	Kontakty kon;
	Saldo sal;
	Kursy_walut kur;
	Typ_operacji typ_operacji;
public:
	Operacja sprawdz(Typ_operacji);
};

class Historia {
	Data data;
	Typ_operacji typ_operacji;
	double wartosc;
	string odbiorca;
};

class Kontakty {
	string nazwa;
	double numer_konta;
};

class Saldo {
	double euro;
	double funt;
	double zloty;
	double dolar;
};

class Kursy_walut {
	Kurs kurs;
public:
	double sprawdz_kurs();
};

class Kurs {
	string symbol;
	double wartosc;
	Data data;
};

class Data{
	int dzien;
	int miesiac;
	int rok;
};