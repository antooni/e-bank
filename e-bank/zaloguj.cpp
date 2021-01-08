#include "zaloguj.h"

Zaloguj::Zaloguj()
{

}

string Zaloguj::weryfikacja(string nazwa, string haslo)
{
	string line;
	string temp;
	fstream plik;
	plik.open("base/baza_logowania.txt", ios::in | ios::out);
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == nazwa) {
			iss >> temp;
			while (true) {
				if (temp == haslo) {
					iss >> temp;
					return temp;
				}
				else {
					return "";
				}
			}
		}
	}
	return "";
}

string Zaloguj::rejestracja(string, string, string, string)
{
	return "";
}

string Zaloguj::wyloguj(string)
{
	return "";
}
