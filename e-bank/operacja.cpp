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
	saldo = new Saldo();
	//Kontakt = NULL;
	//Historia = NULL;
	//Kurs = NULL;
	do_wykonania = new Do_wykonania();
}
void Dane::wypisz_saldo() {
	cout << "Euro: " << saldo->euro << endl << endl;
	cout << "Funt: " << saldo->funt << endl << endl;
	cout << "Zloty: " << saldo->zloty << endl << endl;
	cout << "Dolar: " << saldo->dolar << endl << endl;
}

Operacja::Operacja()
{
	typ = "";
	typ_operacji = "";
	token = "";
	kod_bledu = NULL;
	dane = new Dane();
}
