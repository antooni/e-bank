#include "operacja.h"

Do_wykonania::Do_wykonania()
{
}

Dane::Dane()
{
	saldo = new Saldo();
	vector <Kontakty> kontakty;
	vector <Historia> historia;
	kurs = new Kurs();
	do_wykonania = new Do_wykonania();
	uzytkownik = new Uzytkownik();
}



bool Dane::sprawdz_kwote(double suma, string waluta) {
	if (waluta == "P" && saldo->zloty >= suma) {
		return true;
	}
	else if (waluta == "U" && saldo->dolar >= suma) {
		return true;
	}

	else if (waluta == "G" && saldo->funt >= suma) {
		return true;
	}
	else if (waluta == "E" && saldo->euro >= suma) {
		return true;
	}
	else {
		return false;
	}
}

string Dane::znajdz_numer(string numer) {
	for (int i = 0; i < kontakty.size(); i++) {
		if (kontakty[i].numer == numer)
			return kontakty[i].numer_konta;
	}
	return "";
}

void Dane::wypisz_historia() {
	cout << "Twoja historia: " << endl << endl;
	for (int i = 0; i < historia.size(); i++) {
		cout.width(50);
		cout << "D/M/Y" << endl;
		cout.width(45);
		cout << historia[i].data.dzien << "/" << historia[i].data.miesiac << "/" << historia[i].data.rok << endl << endl;
		cout.width(50);
		cout << "Wartosc: " << historia[i].wartosc << " " << historia[i].waluta << endl << endl;
		cout.width(51);
		cout << "Odbiorca: " << historia[i].odbiorca << endl << endl;
		cout.width(50);
		cout << "Nadawca: " << historia[i].nadawca << endl << endl;
	}
	historia.clear();
}

void Dane::wypisz_kontakty() {
	cout.width(50);
	cout << "Twoje kontakty: " << endl << endl;
	for (int i = 0; i < kontakty.size(); i++) {
		cout.width(50);
		cout << "Numer: " << kontakty[i].numer << endl << endl;
		cout.width(50);
		cout << "Imie: " << kontakty[i].imie << endl << endl;
		cout.width(54);
		cout << "Nazwisko: " << kontakty[i].nazwisko << endl << endl;
		cout.width(57);
		cout << "Numer konta: " << kontakty[i].numer_konta << endl << endl;
	}
	kontakty.clear();
}

void Dane::wypisz_saldo() {
	cout.width(50);
	cout << "Euro: " << saldo->euro << endl << endl;
	cout.width(50);
	cout << "Funt: " << saldo->funt << endl << endl;
	cout.width(51);
	cout << "Zloty: " << saldo->zloty << endl << endl;
	cout.width(51);
	cout << "Dolar: " << saldo->dolar << endl << endl;
}

void Dane::wypisz_kurs() {
	cout.width(50);
	cout << "Euro: " << kurs->euro << endl << endl;
	cout.width(50);
	cout << "Funt: " << kurs->funt << endl << endl;
	cout.width(51);
	cout << "Zloty: " << kurs->zloty << endl << endl;
	cout.width(51);
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
