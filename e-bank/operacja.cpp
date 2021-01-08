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
	kurs = new Kurs();
	do_wykonania = new Do_wykonania();
}
void Dane::wypisz_saldo() {
	cout << "Euro: " << saldo->euro << endl << endl;
	cout << "Funt: " << saldo->funt << endl << endl;
	cout << "Zloty: " << saldo->zloty << endl << endl;
	cout << "Dolar: " << saldo->dolar << endl << endl;
}

void Dane::wypisz_kurs() {
	cout << "Euro: " << kurs->euro << endl << endl;
	cout << "Funt: " << kurs->funt << endl << endl;
	cout << "Zloty: " << kurs->zloty << endl << endl;
	cout << "Dolar: " << kurs->dolar << endl << endl;
}

Operacja::Operacja()
{
	typ = "";
	typ_operacji = "";
	token = "";
	kod_bledu = NULL;
	dane = new Dane();
}
