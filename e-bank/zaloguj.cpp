#include "zaloguj.h"



Zaloguj::Zaloguj()
{
	token = "";
	baza = "base/baza_logowania.txt";
}

string Zaloguj::weryfikacja(string nazwa, string haslo)
{
	string line;
	string temp;
	fstream plik;
	plik.open(baza, ios::in | ios::out);
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == nazwa) {
			iss >> temp;
			while (true) {
				if (temp == haslo) {
					iss >> temp;
					token = temp;
					plik.close();
					return temp;
				}
				else {
					plik.close();
					return "";
				}
			}
		}
	}
	plik.close();
	return "";
}



string Zaloguj::rejestracja(string nazwa, string haslo, string imie , string nazwisko)
{
	
	if (sprawdz_czy_w_bazie(nazwa))
	{
		return "";
	}
	else
	{
		string numer_konta = generuj_nr_konta();

		zapisz_do_bazy(nazwa, haslo, numer_konta);

		konfiguracja_bazy(nazwa, imie, nazwisko, numer_konta);

		return numer_konta;

	}

	
}

string Zaloguj::wyloguj(string)
{
	return "";
}

string Zaloguj::generuj_nr_konta()
{
	srand(time(NULL));

	string numer;
	for (int i = 0; i < 8; i++)
	{
		int random = rand() % 10;
		numer += to_string(random);
	}

	return numer;
}

bool Zaloguj::sprawdz_czy_w_bazie(string nazwa)
{
	string line;
	string temp;
	fstream plik;

	plik.open(baza, ios::in | ios::out);
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == nazwa) {
			plik.close();
			return true;
		}
	}
	plik.close();
	return false;
}

void Zaloguj::zapisz_do_bazy(string nazwa, string haslo, string numer_konta)
{
	ofstream zapisz;
	zapisz.open(baza, ios::out | ios::app);
	zapisz << endl << nazwa << " " << haslo << " " << numer_konta;

	zapisz.close();
}

void Zaloguj::konfiguracja_bazy(string nazwa, string imie, string nazwisko, string numer_konta)
{
	string path = "base/" + numer_konta;

	_mkdir(path.c_str());

	fstream outfile;
	outfile.open(path + "/dane.txt", ios::out | ios::app);
	outfile << imie << " " << nazwisko << " " << nazwa << " " << numer_konta;
	outfile.close();

	outfile.open(path + "/historia.txt", ios::out);
	outfile.close();

	outfile.open(path + "/kontakty.txt", ios::out);
	outfile.close();

	outfile.open(path + "/saldo.txt", ios::out | ios::app);
	outfile << "0.0 0.0 0.0 0.0";
	outfile.close();
}
