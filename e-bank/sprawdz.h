#pragma once

#include<iostream>

using namespace std;

class Data {
	int dzien;
	int miesiac;
	int rok;
};

class Historia {
	Data data;
	double wartosc;
	string odbiorca;
	string nadawca;
};

class Kontakty {
	string nazwa;
	string numer_konta;
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




