#pragma once

#include<iostream>

using namespace std;

class Data {
	int dzien;
	int miesiac;
	int rok;
};

class Typ_operacji {
	string typ_operacji;
public:
	bool sprawdz_czy_wykonaj(string typ_operacji);
};

class Dane {
	string typ_danych;
	double wartosc;
};


class Blad {
	int kod_bledu;
	string informacje;
};

class Operacja {
	Typ_operacji typ_operacji;
	Dane dane;
	int token_sesji;
	Data data_operacji;
	Blad blad;
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

class Kurs {
	string symbol;
	double wartosc;
	Data data;
};

class Kursy_walut {
	Kurs kurs;
public:
	double sprawdz_kurs();
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

