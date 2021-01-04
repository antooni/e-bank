#pragma once
#include "konto.h"
#include "zaloguj.h"
#include "dodatkowe.h"

#include <iostream>

using namespace std;

class UI
{
	int token;
	Konto* konto;
	Uzytkownik* user;
	Zaloguj* zaloguj;

	void obsluga_rejestracji_lub_logowania();
	void obsluga_operacji_lub_wylogowania();

public:
	UI();
	void start();
};

