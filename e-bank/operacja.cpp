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
	saldo = NULL;
	//Kontakt = NULL;
	//Historia = NULL;
	//Kurs = NULL;
	do_wykonania = NULL;
}

Operacja::Operacja()
{
	typ = "";
	typ_operacji = "";
	token = "";
	kod_bledu = NULL;
	dane = NULL;

}
