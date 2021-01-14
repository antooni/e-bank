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
		cout << "Za malo srodkow na koncie lub podano bledna walute" << endl << endl;
		cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
		_getch();
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
	printf("                                            Euro: %.2f \n \n", saldo->euro);
	printf("                                            Funt: %.2f \n \n", saldo->funt);
	printf("                                            Zloty: %.2f \n \n", saldo->zloty);
	printf("                                            Dolar: %.2f \n \n", saldo->dolar);
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

bool Dane::przewalutuj(string waluta, string _waluta, double suma) {
	if (waluta == "P" && saldo->zloty >= suma) {
		saldo->zloty -= suma;
		if (_waluta == "U") {
			saldo->dolar += (suma / kurs->dolar);
		}
		else if (_waluta == "G") {
			saldo->funt += (suma / kurs->funt);
		}
		else if (_waluta == "E") {
			saldo->euro += (suma / kurs->euro);
		}
		return true;
	}
	else if (waluta == "U" && saldo->dolar >= suma) {
		saldo->dolar -= suma;
		if (_waluta == "P") {
			saldo->zloty += (suma * kurs->dolar);
		}
		else if (_waluta == "G") {
			saldo->funt += ((suma * kurs->dolar) / kurs->funt);
		}
		else if (_waluta == "E") {
			saldo->euro += ((suma * kurs->dolar) / kurs->euro);
		}
		return true;
	}

	else if (waluta == "G" && saldo->funt >= suma) {
		saldo->funt -= suma;
		if (_waluta == "P") {
			saldo->zloty += (suma * kurs->funt);
		}
		else if (_waluta == "U") {
			saldo->dolar += ((suma * kurs->funt) / kurs->dolar);
		}
		else if (_waluta == "E") {
			saldo->euro += ((suma * kurs->funt) / kurs->euro);
		}
		return true;
	}
	else if (waluta == "E" && saldo->euro >= suma) {
		saldo->euro -= suma;
		if (_waluta == "P") {
			saldo->zloty += (suma * kurs->euro);
		}
		else if (_waluta == "G") {
			saldo->funt += ((suma * kurs->euro) / kurs->funt);
		}
		else if (_waluta == "U") {
			saldo->dolar += ((suma * kurs->euro) / kurs->dolar);
		}
		return true;
	}
	else {
		cout << "Za malo srodkow na koncie" << endl << endl;
		cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
		_getch();

		return false;
	}
}

Operacja::Operacja()
{
	typ = "";
	typ_operacji = "";
	token = "";
	kod_bledu = NULL;
	dane = new Dane();
}
