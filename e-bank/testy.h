#pragma once

#include <vector>
#include <stdlib.h>

#include "baza.h"
#include "dodatkowe.h"
#include "konto.h"
#include "operacja.h"
#include "sprawdz.h"
#include "wykonaj.h"
#include "zaloguj.h"

using namespace std;

void otworz_sekcje(string);
void zamknij_sekcje();

bool test_poprawne_logowanie();
bool test_niepoprawne_logowanie();

bool test_poprawna_rejestracja();
bool test_niepoprawna_rejestracja();

bool test_saldo();
bool test_kontakty();
bool test_historia();
bool test_kursy();

bool test_przelew();
bool test_przelew_do_kontaktu();
bool test_dodaj_kontakt();
bool test_wymien_walute();


bool uruchom_testy();

class Test {
	string nazwa;
	string do_wyswietlenia;

public:
	template<typename T>
	bool sprawdz_rownosc(T, T);
	bool sprawdz_czy_poprawna(bool);
	void ustaw_nazwe(string);

	Test(string);

};

template<typename T>
inline bool Test::sprawdz_rownosc(T a, T b)
{
	cout << " # " << nazwa << " : ";
	if(a != b) {
		printf("\x1B[31m  niezdany \033[0m \n");
		return false;
	}
	printf("\x1B[32m zdany \033[0m \n");
	return true;
}
