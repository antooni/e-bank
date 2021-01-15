#include "testy.h"

bool uruchom_testy()
{
	int licznik_bledow = 0;
	cout << "=== Wykonuje testy oprogramowania e-bank ===" << endl << endl;

	otworz_sekcje("LOGOWANIE");
	
	Test* t = NULL;
	t = new Test("poprawne logowanie");
	licznik_bledow += t->sprawdz_czy_poprawna(test_poprawne_logowanie("test","1234"));

	t->ustaw_nazwe("niepoprawne logowanie");
	licznik_bledow += t->sprawdz_czy_poprawna(!test_poprawne_logowanie("test", "bledne_haslo"));

	zamknij_sekcje();

	otworz_sekcje("REJESTRACJA");

	t->ustaw_nazwe("poprawna rejestracja");
	licznik_bledow += t->sprawdz_czy_poprawna(test_poprawna_rejestracja("1234567890","1234","test","test"));

	t->ustaw_nazwe("niepoprawne rejestracja");
	licznik_bledow += t->sprawdz_czy_poprawna(!test_poprawna_rejestracja("test", "p", "", ""));

	zamknij_sekcje();

	otworz_sekcje("SPRAWDZ");

	t->ustaw_nazwe("sprawdz saldo");
	licznik_bledow += t->sprawdz_czy_poprawna(test_saldo());

	t->ustaw_nazwe("sprawdz kontakty");
	licznik_bledow += t->sprawdz_czy_poprawna(test_kontakty());

	t->ustaw_nazwe("sprawdz historie");
	licznik_bledow += t->sprawdz_czy_poprawna(test_historia());

	t->ustaw_nazwe("sprawdz kursy");
	licznik_bledow += t->sprawdz_czy_poprawna(test_kursy());

	zamknij_sekcje();

	otworz_sekcje("WYKONAJ");

	t->ustaw_nazwe("przelew");
	licznik_bledow += t->sprawdz_czy_poprawna(test_przelew());

	t->ustaw_nazwe("przelew do kontaktu");
	licznik_bledow += t->sprawdz_czy_poprawna(test_przelew_do_kontaktu());

	t->ustaw_nazwe("dodaj kontakt");
	licznik_bledow += t->sprawdz_czy_poprawna(test_dodaj_kontakt());

	t->ustaw_nazwe("wymiana walut");
	licznik_bledow += t->sprawdz_czy_poprawna(test_wymien_walute());

	zamknij_sekcje();

	otworz_sekcje("WYLOGUJ");

	t->ustaw_nazwe("poprawne wylogowanie");
	licznik_bledow += t->sprawdz_czy_poprawna(test_poprawne_wylogowanie("test","1234"));

	zamknij_sekcje();

	otworz_sekcje("USUN KONTO");

	t->ustaw_nazwe("usuwanie konta");
	licznik_bledow += t->sprawdz_czy_poprawna(test_usuwanie_konta("1234567890", "1234"));

	zamknij_sekcje();

	if (licznik_bledow) {
		cout << "=========================================== " << endl;
		printf("\x1B[31m | ERROR | liczba bledow : %d \033[0m \n", licznik_bledow);
		cout << "=========================================== " << endl;
	}
	else
	{
		cout << "=========================================== " << endl;
		printf("\x1B[32m 0 bledow : wszystkie testy zdane \033[0m \n");
		cout << "=========================================== " << endl;
	}
	

	return false;
}

int Test::sprawdz_czy_poprawna(bool _v)
{
	cout << " # " << nazwa << " : ";
	if (_v == false) {
		printf("\x1B[31m  niezdany \033[0m \n");
		return 1;
	}
	printf("\x1B[32m zdany \033[0m \n");
	return 0;
}

void Test::ustaw_nazwe(string _nazwa)
{
	nazwa = _nazwa;
}

Test::Test(string _nazwa)
{
	nazwa = _nazwa;
}

// helpers
void otworz_sekcje(string _nazwa)
{
	cout << " --- " << _nazwa << " --------" << endl;
}

void zamknij_sekcje()
{
	cout << " ------------------------- " << endl << endl;
}


