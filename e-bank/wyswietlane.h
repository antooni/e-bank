#pragma once
#include <iostream>
#include <conio.h>
#include "zaloguj.h"
#include "ui.h"

using namespace std;
void menu();
void menu_sprawdz();
void menu_wykonaj();
void menu_operacji();
void podaj_dane_login(string& email, string& haslo);
void podan_dane_rejestruj(string& email, string& imie, string& haslo, string& nazwisko);
void stopka(Operacja operacja, int saldo);
void wczytaj_haslo(string& haslo);