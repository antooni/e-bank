#include "ui.h"
#include "konto.h"
#include "zaloguj.h"
#include "operacja.h"
#include "testy.h"
#include "wyswietlane.h"

template <typename T>					
T wczytaj_dane(T& d) {							//funkcja pobiera dane uzytkownika w przypadku gdy sa poprawne
	cin >> d;
	while (cin.fail() == true) {
		cout << "Podales niedozwolona dane podaj jeszcze raz" << endl;
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cin >> d;
	}
	return d;
}

UI::UI()
{
	token = "";
	konto = NULL;
	user = NULL;
	zaloguj = NULL;
	test = false;
}

void UI::start()
{
	//test = true;
	if (test) {
		uruchom_testy();
		return;
	}



	while (true)
	{
		if (token == "")
		{
			if(obsluga_rejestracji_lub_logowania()) break;
			continue;
		}
		else
		{
			obsluga_operacji_lub_wylogowania();
			continue;
		}
	}
}

bool UI::obsluga_rejestracji_lub_logowania()
{
	zaloguj = new Zaloguj();

	while (true)
	{
		// wyswietl menu();
		menu();

		int wybor = 0;
		wczytaj_dane(wybor);	
		//wczytuje dane i sprawdza ich poprawnosc typu

		// logowanie
		if (wybor == 1)
		{
			string email = "";
			string haslo = "";
			podaj_dane_login(email, haslo);

			token = zaloguj->weryfikacja(email, haslo);

			//wyjdz jezeli mu sie udalo
			if (token != "") {
				break;
			}
			else
				cout << "Podano bledne dane" << endl;
		}
		//rejestracja
		else if (wybor == 2)
		{
			system("cls");
			string email = "";
			string haslo = "";
			string imie = "";
			string nazwisko = "";

			podan_dane_rejestruj(email, imie, haslo, nazwisko);
			token = zaloguj->rejestracja(email, haslo, imie, nazwisko);

			if (token == "")
			{
				cout << " ! BLAD REJESTRACJI ! " << endl;
			}
			else
			{
				cout << "Rejestracja zakonczona powodzeniem, czy chcesz sie zalogowac ? (t/n) : ";
				string _w = "";
				cin >> _w;
				if (_w == "n" || _w == "N") 
					token = "";
			}
			break;
		}
		//zamkniecie panelu logowania, powrot do strony startowej
		else if (wybor == 3)
		{
			cout << endl << endl << endl << " + Dziekujemy za skorzystanie z uslug naszego banku, zapraszamy ponownie :-)" << endl << endl << endl;
			return true;
		}
		
	}
	return false;
}

void UI::obsluga_operacji_lub_wylogowania()
{
	Operacja operacja = Operacja();
	konto = new Konto();
	user = new Uzytkownik();
		//utworzenie obiektow potrzenych do realizacji operacji
	
	while (true)
	{
		operacja.token = token;		
									
		system("cls");
		operacja.typ_operacji = "saldo";
		konto->sprawdz(operacja);				//ustawia saldo
		konto->wczytaj_stopka(operacja);		// ustawia uzytkownia
		stopka(operacja, operacja.dane->saldo->zloty);
	
		menu_operacji();
		int wybor = 0;
		// zbierz dane o typie operacji
		wczytaj_dane(wybor);
		system("cls");
		if (wybor == 3)				//wylogowywanie  przenosi do panelu startowego
		{					
			token = zaloguj->wyloguj(token);
			break;
		}
		else if (wybor == 1)				//sprawdzanie danych
		{				
			stopka(operacja, operacja.dane->saldo->zloty);
			menu_sprawdz();
			wczytaj_dane(wybor);
			system("cls");
			operacja.typ = "sprawdz";
			if (wybor == 1) {								//saldo
			
				operacja.typ_operacji = "saldo";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_saldo();
			}
			else if (wybor == 2) {					//kontakt
				operacja.typ_operacji = "kontakty";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_kontakty();
			}
			else if (wybor == 3) {					//historia
				operacja.typ_operacji = "historia";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_historia();
			}
			else if (wybor == 4) {				//kursy
				operacja.typ_operacji = "kurs";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_kurs();
			}
			else if (wybor == 0) {
				continue;
			}
			
				cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
				_getch();
				system("cls");

		}
		else if (wybor == 2)						//wykonywanie operacji
		{
			double suma;
			string temp;
			string _waluta;
			string waluta;
			operacja.typ = "wykonaj";
			stopka(operacja, operacja.dane->saldo->zloty);
			menu_wykonaj(); 
			wczytaj_dane(wybor);
			system("cls");
			
			if (wybor == 1) { //Przelew dowolny
				cout << "Numer konta do przelewu: ";
				cin >> temp;
				cout << "Kwota przelewu: ";
				cin >> suma;
				cout << "Waluta(PLN,EUR,USD,GBP): ";
				cin >> _waluta;
				waluta = toupper(_waluta[0]);

				
				przelew(operacja, temp, suma, waluta);
				system("cls");
			}

			else if (wybor == 2) { //Przleew do kontatku
				string numer;
				operacja.typ_operacji = "kontakty";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_kontakty();
				cout << "Id kontaktu: ";
				cin >> numer;
				konto->sprawdz(operacja);
				if (stoi(numer) <= operacja.dane->kontakty.size()) {
					temp = operacja.dane->znajdz_numer(numer);
					cout << "Kwota przelewu: ";
					cin >> suma;
					cout << "Waluta(PLN,EUR,USD,GBP): ";
					cin >> _waluta;
					waluta = toupper(_waluta[0]);

					przelew(operacja, temp, suma, waluta);

					operacja.dane->kontakty.clear();
				}
				else {
					cout << "Podany numer kontaktu nie istnieje" << endl;
					cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
					_getch();
				}
				system("cls");
			}

			else if (wybor == 3) { //Dodaj kontakt
				operacja.typ_operacji = "kontakty";
				cout << "Imie: ";
				cin >> temp;
				operacja.dane->do_wykonania->kontakty.imie = temp;
				cout << "Nazwisko: ";
				cin >> temp;
				operacja.dane->do_wykonania->kontakty.nazwisko = temp;
				cout << "Numer konta: ";
				cin >> temp;
				operacja.dane->do_wykonania->kontakty.numer_konta = temp;

				konto->sprawdz(operacja);
				operacja.dane->do_wykonania->kontakty.numer = to_string(operacja.dane->kontakty.size() + 1);

				operacja.typ_operacji = "zapisz_kontakt";
				konto->wykonaj(operacja);
				operacja.dane->kontakty.clear();
				system("cls");
			}

			else if (wybor == 4) { // Przewalutuj
				operacja.typ_operacji = "saldo";
				konto->sprawdz(operacja);
				cout.width(48);
				cout << "Saldo:" << endl;
				operacja.dane->wypisz_saldo();

				operacja.typ_operacji = "kurs";
				konto->sprawdz(operacja);
				cout.width(47);
				cout << "Kurs:" << endl;
				operacja.dane->wypisz_kurs();

				cout << "Z(PLN,EUR,USD,GBP): ";
				cin >> waluta;
				cout << "Na(PLN,EUR,USD,GBP): ";
				cin >> _waluta;
				waluta = toupper(waluta[0]);
				_waluta = toupper(_waluta[0]);
				
				cout << "Wartosc: ";
				cin >> suma;

				if (operacja.dane->przewalutuj(waluta, _waluta, suma)) {
					cout << "Operacja przewalutowania zostala potwierdzona" << endl;
					cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
					operacja.typ_operacji = "zapisz_saldo";
					konto->wykonaj(operacja);
					_getch();
				}
				else {
					cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
					_getch();
					operacja.kod_bledu = 2;
				}
				system("cls");
				
			}
		}
		else
		{
			cout << "Podaj poprawny numer operacji" << endl;
		}
	}
}

int UI::przelew(Operacja operacja, string temp, double suma, string waluta) {
	Operacja odbiorca = Operacja();
	odbiorca.token = temp;
	bool check;
	operacja.typ_operacji = "saldo";
	konto->sprawdz(operacja);
	check = operacja.dane->sprawdz_kwote(suma, waluta);
	if (check) {
		if (odbiorca.token == operacja.token) {
			cout << "Nie mozesz przeslac pieniedzy na swoje konto" << endl;
			cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
			_getch();
		}
		else {
			if (zaloguj->sprawdz_czy_w_bazie(odbiorca.token)) {
				odbiorca.typ_operacji = "saldo";
				konto->sprawdz(odbiorca);
				if (waluta == "P") {
					odbiorca.dane->saldo->zloty += suma;
					operacja.dane->saldo->zloty -= suma;
					odbiorca.dane->do_wykonania->historia.waluta = "PLN";
					operacja.dane->do_wykonania->historia.waluta = "PLN";
				}
				else if (waluta == "U") {
					odbiorca.dane->saldo->dolar += suma;
					operacja.dane->saldo->dolar -= suma;
					odbiorca.dane->do_wykonania->historia.waluta = "USD";
					operacja.dane->do_wykonania->historia.waluta = "USD";
				}
				else if (waluta == "E") {
					odbiorca.dane->saldo->euro += suma;
					operacja.dane->saldo->euro -= suma;
					odbiorca.dane->do_wykonania->historia.waluta = "EUR";
					operacja.dane->do_wykonania->historia.waluta = "EUR";
				}
				else if (waluta == "G") {
					odbiorca.dane->saldo->funt += suma;
					operacja.dane->saldo->funt -= suma;
					odbiorca.dane->do_wykonania->historia.waluta = "GBP";
					operacja.dane->do_wykonania->historia.waluta = "GBP";
				}
				else {
					return 0;
				}
				odbiorca.typ_operacji = "zapisz_saldo";
				konto->wykonaj(odbiorca);
				
				operacja.typ_operacji = "zapisz_saldo";
				konto->wykonaj(operacja);

				//SYSTEMTIME st;
				//GetSystemTime(&st);
				operacja.dane->do_wykonania->historia.data.dzien = "13";
				operacja.dane->do_wykonania->historia.data.miesiac = "01";
				operacja.dane->do_wykonania->historia.data.rok = "2021";

				operacja.dane->do_wykonania->historia.wartosc = suma * (-1);
				operacja.dane->do_wykonania->historia.nadawca = operacja.token;
				operacja.dane->do_wykonania->historia.odbiorca = odbiorca.token;

				odbiorca.dane->do_wykonania->historia.data.dzien = "13";
				odbiorca.dane->do_wykonania->historia.data.miesiac = "01";
				odbiorca.dane->do_wykonania->historia.data.rok = "2021";

				odbiorca.dane->do_wykonania->historia.wartosc = suma;
				//odbiorca.dane->do_wykonania->historia.waluta = waluta;
				odbiorca.dane->do_wykonania->historia.nadawca = operacja.token;
				odbiorca.dane->do_wykonania->historia.odbiorca = odbiorca.token;

				operacja.typ_operacji = "zapisz_historie";
				odbiorca.typ_operacji = "zapisz_historie";

				konto->wykonaj(operacja);
				konto->wykonaj(odbiorca);
			}
			else {
				if (waluta == "P") {
					operacja.dane->saldo->zloty -= suma;
					operacja.dane->do_wykonania->historia.waluta = "PLN";
				}
				else if (waluta == "U") {
					operacja.dane->saldo->dolar -= suma;
					operacja.dane->do_wykonania->historia.waluta = "USD";
				}
				else if (waluta == "E") {
					operacja.dane->saldo->euro -= suma;
					operacja.dane->do_wykonania->historia.waluta = "EUR";
				}
				else if (waluta == "G") {
					operacja.dane->saldo->funt -= suma;
					operacja.dane->do_wykonania->historia.waluta = "GBP";
				}
				operacja.typ_operacji = "zapisz_saldo";
				konto->wykonaj(operacja);

				//SYSTEMTIME st;
				//GetSystemTime(&st);
				operacja.dane->do_wykonania->historia.data.dzien = "13";
				operacja.dane->do_wykonania->historia.data.miesiac = "01";
				operacja.dane->do_wykonania->historia.data.rok = "2021";

				operacja.dane->do_wykonania->historia.wartosc = suma * (-1);
				operacja.dane->do_wykonania->historia.nadawca = operacja.token;
				operacja.dane->do_wykonania->historia.odbiorca = temp;

				operacja.typ_operacji = "zapisz_historie";
				konto->wykonaj(operacja);
				operacja.typ_operacji = "przelew zewnetrzny";
				konto->wykonaj(operacja);
			}
		}
		
	}
	else {
		operacja.kod_bledu = 2;
	}
}