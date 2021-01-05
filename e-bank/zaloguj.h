#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

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
};

