#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Token
{
	int ID_user;
	hash<string> token;
};


class Zaloguj
{
	Token* token_sesji;
	string baza;

	

public:
	Zaloguj(string);
	bool sprawdz(string, string);
};

