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
	friend class UI;
	friend class Dane;
	friend class Do_wykonania;
	friend class Konto;
	string dzien;
	string miesiac;
	string rok;
	Data();
};

class Historia {
	friend class Baza;
	friend class Dane;
	friend class Do_wykonania;
	friend class Konto;
	friend class UI;
	Data data;
	double wartosc;
	string odbiorca;
	string nadawca;
	string waluta;
	Historia();
};

class Kontakty {
	friend class Baza;
	friend class Dane;
	friend class Do_wykonania;
	friend class UI;
	string numer;
	string imie;
	string nazwisko;
	string numer_konta;
	Kontakty();
};

class Saldo {
	friend class Baza;
	friend class UI;
	friend class Dane;
	friend class Do_wykonania;
	friend class Konto;
	double euro;
	double funt;
	double zloty;
	double dolar;
	Saldo();
};

class Kurs {
	friend class Baza;
	friend class Dane;
	friend class Do_wykonania;
	double euro;
	double funt;
	double zloty;
	double dolar;
	Kurs();
};