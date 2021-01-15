#pragma once

#include <vector>
#include <stdlib.h>

#include "baza.h"
#include "dodatkowe.h"
#include "konto.h"
#include "operacja.h"
#include "sprawdz.h"
#include "wykonaj.h"
#include "ui.h"
#include "zaloguj.h"

using namespace std;

// testy z zaloguj
bool test_poprawne_logowanie(string, string);
bool test_poprawna_rejestracja(string nazwa, string haslo, string imie, string nazwisko);
bool test_poprawne_wylogowanie(string, string);
bool test_usuwanie_konta(string, string);

// testy z sprawdz
bool test_saldo();
bool test_kontakty();
bool test_historia();
bool test_kursy();

// testy z wykonaj
bool test_przelew();
bool test_przelew_do_kontaktu();
bool test_dodaj_kontakt();
bool test_wymien_walute();

// wrapper
bool uruchom_testy();

class Test {
	string nazwa;
	string do_wyswietlenia;

public:
	template<typename T>
	int sprawdz_rownosc(T, T);
	int sprawdz_czy_poprawna(bool);
	void ustaw_nazwe(string);

	Test(string);

};

template<typename T>
inline int Test::sprawdz_rownosc(T a, T b)
{
	cout << " # " << nazwa << " : ";
	if(a != b) {
		printf("\x1B[31m  niezdany \033[0m \n");
		return 1;
	}
	printf("\x1B[32m zdany \033[0m \n");
	return 0;
}

// helpers
void otworz_sekcje(string);
void zamknij_sekcje();