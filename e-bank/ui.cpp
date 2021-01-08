#include "ui.h"
#include "konto.h"
#include "zaloguj.h"
#include "operacja.h"

void podaj_dane(string& email, string& haslo) {
	system("cls");
	cout << "Podaj email: ";
	cin >> email;
	cout << "Podaj haslo: ";
	cin >> haslo;
}

void menu() {
	cout.width(60);
	cout << "Aby sie zalogowac wybierz 1" << endl<<endl;
	cout.width(64);
	cout << "Aby sie zarejestrowac wybierz 2" << endl<<endl;
	cout.width(56);
	cout << "Aby sie wyjsc wybierz 3" << endl << endl;
}

void menu_sprawdz() {			//wyrownac najlepiej w osobnym projekcie
	cout.width(62);
	cout << "Aby sprawdzic saldo wybierz 1" << endl << endl;
	cout.width(64);
	cout << "Aby sprawdzic kontaky wybierz 2" << endl << endl;
	cout.width(65);
	cout << "Aby sprawdzic historie wybierz 3" << endl << endl;
	cout.width(68);
	cout << "Aby sprawdzic kursy walut wybierz 4" << endl << endl;
}

void menu_operacji() {
	cout.width(61);
	cout << "Aby sprawdzic dane wybierz 1" << endl << endl;
	cout.width(63);
	cout << "Aby wykonac operacje wybierz 2" << endl << endl;
	cout.width(60);
	cout << "Aby wylogowac sie wybierz 3" << endl << endl;
}

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
}

void UI::start()
{
	while (true)
	{
		if (token == "")
		{
			obsluga_rejestracji_lub_logowania();
			continue;
		}
		else
		{
			obsluga_operacji_lub_wylogowania();
			continue;
		}
	}
	// tutaj jeszcze podjerzewam bedzie brakowac wyjscia z tego while'a
	// moze jakis kod niech returnuje ta funkcja obsluga...
}

void UI::obsluga_rejestracji_lub_logowania()
{
	zaloguj = new Zaloguj();
	while (true)
	{
		// wyswietl menu();
		menu();
		//cout << "Aby sie zalogowac wybierz 1" << endl;

		int wybor = 0;
		// zbierz dane uzytkownika ();
		wczytaj_dane(wybor);
		// logowanie
		if (wybor == 1)
		{
			string email = "";
			string haslo = "";
			podaj_dane(email, haslo);

			token = zaloguj->weryfikacja(email, haslo);

			//info o powodzeniu lub nie ()



			//wyjdz jezeli mu sie udalo
			if (token != "") {
				system("cls");
				cout.width(60);
				cout << "Poprawnie zalogowano" << endl << endl;
				break;
			}
			else
				cout << "Podano bledne dane" << endl;
		}
		//rejestracja
		else if (wybor == 2)
		{
			string email = "";
			string haslo = "";
			string imie = "";
			string nazwisko = "";

			cin >> email;
			cin >> haslo;
			cin >> imie;
			cin >> nazwisko;
			//popros o dane ()
			zaloguj->rejestracja(email, haslo, imie, nazwisko);

			//info o powodzeniu lub nie()
			// czy chcesz sie zalogowac?

			// if chce sie zalogowac
			//token = zaloguj->weryfikacja();

			// info o powodzeniu lub nie()

			// moze zrobic obiekt Menu czy coś
			// żeby te info i bledy oddzielic od reszty
			// i zeby nie wyszedl nam z tego jeden ogromny obiekt

			// wyjdz jezeli mu sie udalo
			break;
		}
		//zamkniecie panelu logowania, powrot do strony startowej
		else if (wybor == 3)
		{
			break;
		}
		// podaj poprawny numer operacji
		else
		{
			// cout podaj normalny numer
		}
	}

}

void UI::obsluga_operacji_lub_wylogowania()
{
	Operacja operacja = Operacja();
	konto = new Konto();
	user = new Uzytkownik();

	
	while (true)
	{
		operacja.token = token;		//operacja nie miala przypisanego tokenu
									//spr czy tak ma to zostac lub czy nie powinien byc przypisany w zaloguj
		// !!!!
	// tu jeszcze przydaloby sie odpalic sprawdz() zeby :
	// ustawic : nr_konta, saldo dla : konto
	// ustawic : imie, nazwisko, numer_konta, email
	// bo mogly ulec jakies zmianie

	// wyswietl menu()
	// dalbym tutaj jakis naglowek w stylu
	// Antoni Pawlak  |  saldo : 100 BTC  |  numer konta : 112132

	// ==========================================================
		menu_operacji();
		int wybor = 0;
		// zbierz dane o typie operacji
		wczytaj_dane(wybor);
		system("cls");
		if (wybor == 3)
		{
			//wyswietl info wylogowanie();
			//może jakieś dodatkowe pytanie czy na pewno chce sie wylogowac
			token = zaloguj->wyloguj(token);
			break;
		}
		else if (wybor == 1)
		{												
			menu_sprawdz();
			wczytaj_dane(wybor);
			system("cls");
			operacja.typ_operacji = "sprawdz";
			if (wybor == 1) {								//saldo
			
				// operacja.typ = "sprawdz"
				// wyswietl menu sprawdzanie();

				//cin >> [typ operacji]
				// operacja.typ_operacji = [typ operacji]
				operacja.typ_operacji = "saldo";
				konto->sprawdz(operacja);
				operacja.dane->wypisz_saldo();

				// wyswietl info(operacja);
				// w tej metodzie jakas obsluga bledow najpierw aktualne (jedyny mozliwy blad to otwarcie pliku)
				// a jak jest powodzenie to wyswietlic pobrane Dane


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
			
				cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
				_getch();
				system("cls");

		}
		else if (wybor == 2)
		{
			// operacja.typ = "wykonaj"
			// wyswietl menu wykonaj();

			// cin >> [typ_operacji]
			// operacja.typ_operacji = typ_operacji;

			// switch( [typ_operacji] )

			// w zaleznosci od typu operacji zbierz potrzebne dane
			// przyklad
			// case [przelew] :

			// operacja = konto.sprawdz( [saldo] ); //ta linijka jest po to zeby miec aktualne saldo

			// operacja.dane.do_wykonania.nadawca = konto.numer;
			// operacja.dane.do_wykonania.adresat = cin>>podaj numer adresata;
			// operacja.dane.do_wykonania.suma = cin >> podaj ile chcesz przelac;

			 operacja = konto->wykonaj(operacja);

			//wyswietl info()



		}
		else
		{
			// podaj poprawny numer operacji
		}
	}
}
