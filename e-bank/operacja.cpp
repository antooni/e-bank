#include "operacja.h"

Do_wykonania::Do_wykonania()
{
	nadawca = "";
	adresat = "";
	suma = NULL;
	//Kontakt = NULL;
}

Dane::Dane()
{
	// saldo = NULL;
	//Kontakt = NULL;
	//Historia = NULL;
	//Kurs = NULL;
	do_wykonania = new Do_wykonania();
}

Operacja::Operacja()
{
	typ = "";
	typ_operacji = "";
	token = "";
	kod_bledu = NULL;
	dane = new Dane();
}
