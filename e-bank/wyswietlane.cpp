#include "wyswietlane.h"



void menu() {
	cout.width(60);
	cout << "Aby sie zalogowac wybierz 1" << endl << endl;
	cout.width(64);
	cout << "Aby sie zarejestrowac wybierz 2" << endl << endl;
	cout.width(56);
	cout << "Aby zakonczyc wybierz 3" << endl << endl;
}

void menu_sprawdz() {
	cout.width(62);
	cout << "Aby sprawdzic saldo wybierz 1" << endl << endl;
	cout.width(64);
	cout << "Aby sprawdzic kontaky wybierz 2" << endl << endl;
	cout.width(65);
	cout << "Aby sprawdzic historie wybierz 3" << endl << endl;
	cout.width(68);
	cout << "Aby sprawdzic kursy walut wybierz 4" << endl << endl;
	cout.width(53);
	cout << "Aby wrocic wybierz 0" << endl << endl;
}

void menu_wykonaj() {
	cout.width(62);
	cout << "Aby wykonac dowolny przelew 1" << endl << endl;
	cout.width(66);
	cout << "Aby wykonac przelew do kontaktu 2" << endl << endl;
	cout.width(57);
	cout << "Aby dodac nowy kontakt 3" << endl << endl;
	cout.width(54);
	cout << "Aby wymienic waluty 4" << endl << endl;
	cout.width(53);
	cout << "Aby wrocic wybierz 0" << endl << endl;
}

void menu_operacji() {
	cout.width(61);
	cout << "Aby sprawdzic dane wybierz 1" << endl << endl;
	cout.width(63);
	cout << "Aby wykonac operacje wybierz 2" << endl << endl;
	cout.width(60);
	cout << "Aby wylogowac sie wybierz 3" << endl << endl;
}

void podaj_dane_login(string& email, string& haslo) {
	system("cls");
	cout << "Panel logowania do e-bank" << endl;
	cout << "========================" << endl;
	cout << "Podaj email: ";
	cin >> email;
	cout << "Podaj haslo: ";
	wczytaj_haslo(haslo);
	haslo = to_string(hash<string>{}(haslo)); //hashowanie hasla
}

void podan_dane_rejestruj(string& email, string& imie, string& haslo, string& nazwisko) {
	cout << "Panel rejestracji do e-bank" << endl;
	cout << "==========================" << endl;

	cout << "Podaj mail: ";
	cin >> email;
	cout << "Podaj haslo: ";
	wczytaj_haslo(haslo);
	haslo = to_string(hash<string>{}(haslo)); // hashowanie hasla
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
}
void stopka(Operacja operacja, int saldo) {
	cout.width(30);
	cout << operacja.dane->uzytkownik->imie << " ";
	cout << operacja.dane->uzytkownik->nazwisko;
	cout << "  |  ";
	cout << "saldo : " << saldo << " pln";
	cout << "  |  ";
	cout << "numer konta : " << operacja.dane->uzytkownik->numer_konta << endl << endl << endl;
}


void wczytaj_haslo(string& haslo) {					//zastepuje wpisywane haslo kropkami
	char znak;
	for (int i = 0; (znak = _getch()) != '\r'; i++)
	{
		if (znak == 8) {
			haslo.pop_back();
			cout << "\b \b";
		}
		else {
			cout << '*';
			haslo += znak;
		}
	}
	cout << endl;
}