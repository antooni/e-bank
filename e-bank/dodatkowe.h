#pragma once

#include <iostream>
using namespace std;

class Uzytkownik {
	string imie;
	string nazwisko;
	string numer_konta;
	string email;
};


class Data {
	friend class Baza;
	friend class Historia;
	friend class Dane;
	int dzien;
	int miesiac;
	int rok;
	Data();
};

class Historia {
	friend class Baza;
	friend class Dane;
	Data data;
	double wartosc;
	string odbiorca;
	string nadawca;
	Historia();
};

class Kontakty {
	friend class Baza;
	friend class Dane;
	string imie;
	string nazwisko;
	string numer_konta;
	Kontakty();
};

class Saldo {
	friend class Baza;
	friend class Dane;
	double euro;
	double funt;
	double zloty;
	double dolar;
	Saldo();
};

class Kurs {
	friend class Baza;
	friend class Dane;
	double euro;
	double funt;
	double zloty;
	double dolar;
	Kurs();
};
