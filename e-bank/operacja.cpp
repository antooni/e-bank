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
	saldo = new Saldo();
	vector <Kontakty> kontakty;
	vector <Historia> historia;
	kurs = new Kurs();
	do_wykonania = new Do_wykonania();
}
void Dane::wypisz_historia() {
	cout << "Twoja historia: " << endl << endl;
	for (int i = 0; i < historia.size(); i++) {
		cout << "D/M/Y" << endl;
		cout << historia[i].data.dzien << "/" << historia[i].data.miesiac << "/" << historia[i].data.rok << endl << endl;
		cout << "Wartosc: " << historia[i].wartosc << endl << endl;
		cout << "Odbiorca: " << historia[i].odbiorca << endl << endl;
		cout << "Nadawca: " << historia[i].nadawca << endl << endl;
	}
	historia.clear();
}

void Dane::wypisz_kontakty() {
	cout << "Twoje kontakty: " << endl << endl;
	for (int i = 0; i < kontakty.size(); i++) {
		cout << "Imie: " << kontakty[i].imie << endl << endl;
		cout << "Nazwisko: " << kontakty[i].nazwisko << endl << endl;
		cout << "Numer konta: " << kontakty[i].numer_konta << endl << endl;
	}
	kontakty.clear();
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
