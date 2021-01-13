#pragma once
#include "konto.h"
#include "zaloguj.h"
#include "dodatkowe.h"

#include <iostream>
#include <conio.h>


using namespace std;

class UI
{
	string token;
	Konto* konto;
	Uzytkownik* user;
	Zaloguj* zaloguj;
	bool test;
	void przelew(Operacja, string, double);
	void obsluga_rejestracji_lub_logowania();
	void obsluga_operacji_lub_wylogowania();

public:
	UI();
	void start();
};

