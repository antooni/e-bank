#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>    
#include <time.h>   
#include <direct.h>


using namespace std;

class Zaloguj
{
	string token;
	string baza;

public:
	Zaloguj();
	string weryfikacja(string, string);
	string rejestracja(string, string, string, string);
	string wyloguj(string);
	string generuj_nr_konta();
	bool sprawdz_czy_w_bazie(string);
	void zapisz_do_bazy(string, string, string);
	void konfiguracja_bazy(string, string, string,string);
};

