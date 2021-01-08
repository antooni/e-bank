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
			if (token != "")
				break;
			else
				cout << "bledne dane" << endl;
		}
		//rejestracja
		else if (wybor == 2)
		{
			string email = "";
			string haslo = "";
			string imie = "";
			string nazwisko = "";
			//popros o dane ()
			zaloguj->rejestracja(email, haslo, imie, nazwisko);

			//info o powodzeniu lub nie()
			// czy chcesz sie zalogowac?

			// if chce sie zalogowac
			//token = zaloguj->weryfikacja();

			// info o powodzeniu lub nie()

			// moze zrobic obiekt Menu czy coœ
			// ¿eby te info i bledy oddzielic od reszty
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
		cout << "git";
		// !!!!
	// tu jeszcze przydaloby sie odpalic sprawdz() zeby :
	// ustawic : nr_konta, saldo dla : konto
	// ustawic : imie, nazwisko, numer_konta, email
	// bo mogly ulec jakies zmianie

	// wyswietl menu()
	// dalbym tutaj jakis naglowek w stylu
	// Antoni Pawlak  |  saldo : 100 BTC  |  numer konta : 112132

	// ==========================================================

		int wybor = 0;
		// zbierz dane o typie operacji
		if (wybor == 3)
		{
			//wyswietl info wylogowanie();
			//mo¿e jakieœ dodatkowe pytanie czy na pewno chce sie wylogowac
			token = zaloguj->wyloguj(token);
			break;
		}
		else if (wybor == 1)
		{
			// operacja.typ = "sprawdz"
			// wyswietl menu sprawdzanie();

			//cin >> [typ operacji]
			// operacja.typ_operacji = [typ operacji]

			operacja = konto->sprawdz(operacja);

			// wyswietl info(operacja);
			// w tej metodzie jakas obsluga bledow najpierw
			// a jak jest powodzenie to wyswietlic pobrane Dane

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
