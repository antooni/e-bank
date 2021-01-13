#pragma once
#include "operacja.h"
#include "sprawdz.h"
#include "wykonaj.h"

#include<iostream>
#include<fstream>
#include <sstream>

class Konto: public Wykonaj, public Sprawdz{
	string numer;
	double saldo;

public:
	Konto();
};