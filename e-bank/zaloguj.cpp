#include "zaloguj.h"



Zaloguj::Zaloguj()
{
	token = "";
	baza = "base/baza_logowania.txt";
}

string Zaloguj::weryfikacja(string email, string haslo)
{
	string line;
	string temp;
	fstream plik;
	plik.open(baza, ios::in | ios::out);
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == email) {
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



string Zaloguj::rejestracja(string email, string haslo, string imie , string nazwisko)
{
	
	if (sprawdz_czy_w_bazie(email))
	{
		return "";
	}
	else
	{
		string numer_konta = generuj_nr_konta();

		zapisz_do_bazy(email, haslo, numer_konta);

		konfiguracja_bazy(email, imie, nazwisko, numer_konta);

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

bool Zaloguj::sprawdz_czy_w_bazie(string email)
{
	string line;
	string temp;
	fstream plik;
	plik.open(baza, ios::in | ios::out);
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == email) {
			plik.close();
			return true;
		}
	}
	plik.close();
	return false;
}

bool Zaloguj::usun_konto(string _email, string _haslo)
{
	bool res = false;
	string numer = "";

	string line;
	string temp;
	fstream plik;
	plik.open(baza, ios::in | ios::out);

	vector<string> a;

	
	while (getline(plik, line)) {
		istringstream iss(line);
		iss >> temp;
		if (temp == _email) {
			res = true;
			iss >> temp;
			iss >> numer;


		}
		else
		{
			a.push_back(line);
		}
	}
	plik.close();
	plik.open(baza, ios::out | ios::trunc);

	//cout << numer << endl;

	string path = "base/" + numer;
	cout << path << endl;

	//tutaj najpierw wylistowac pliki
	// usunac
	//a potem usunac pusty folder
	_rmdir(path.c_str());


	for (int i = 0; i < a.size(); i++)
	{
		plik << a[i] << endl;
	}
	plik.close();

	return res;
	
}

void Zaloguj::zapisz_do_bazy(string email, string haslo, string numer_konta)
{
	fstream zapisz;
	zapisz.open(baza, ios::out | ios::app);
	//zapisz.seekg(0, ios::end);
	//if (zapisz.tellg() != 0) { zapisz << endl; }
	zapisz << email << " " << haslo << " " << numer_konta;

	zapisz.close();
}

void Zaloguj::konfiguracja_bazy(string email, string imie, string nazwisko, string numer_konta)
{
	string path = "base/" + numer_konta;

	_mkdir(path.c_str());

	fstream outfile;
	outfile.open(path + "/dane.txt", ios::out | ios::app);
	outfile << imie << " " << nazwisko << " " << email << " " << numer_konta;
	outfile.close();

	outfile.open(path + "/historia.txt", ios::out);
	outfile.close();

	outfile.open(path + "/kontakty.txt", ios::out);
	outfile.close();

	outfile.open(path + "/saldo.txt", ios::out | ios::app);
	outfile << "0.0" << endl << "0.0" << endl << "0.0" << endl << "0.0";
	outfile.close();
}
