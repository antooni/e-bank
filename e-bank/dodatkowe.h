#pragma once

#include <iostream>
using namespace std;

class Uzytkownik {
	friend class Dane;
	friend class Baza;
public:
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
	friend bool test_historia();
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
	friend bool test_kontakty();
	friend bool test_przelew_do_kontaktu();
	friend bool test_dodaj_kontakt();
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
	friend bool test_saldo();
	friend bool test_przelew();
	friend bool test_przelew_do_kontaktu();
	friend bool test_wymien_walute();
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
	friend bool test_kursy();
	double euro;
	double funt;
	double zloty;
	double dolar;
	Kurs();
};