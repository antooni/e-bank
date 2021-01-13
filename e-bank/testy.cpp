#include "testy.h"

bool Test::sprawdz_czy_poprawna(bool _v)
{
	cout <<" # "<< nazwa << " : ";
	if (_v == false) {
		printf("\x1B[31m  niezdany \033[0m \n");		
		return false;
	}
	printf("\x1B[32m zdany \033[0m \n");
	return true;
}

void Test::ustaw_nazwe(string _nazwa)
{
	nazwa = _nazwa;
}

Test::Test(string _nazwa)
{
	nazwa = _nazwa;
}

bool uruchom_testy()
{
	cout << "=== Wykonuje testy oprogramowania e-bank ===" << endl << endl;

	otworz_sekcje("LOGOWANIE");
	
	Test* t = NULL;
	t = new Test("poprawne logowanie");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("niepoprawne logowanie");
	t->sprawdz_czy_poprawna(true);

	zamknij_sekcje();

	otworz_sekcje("REJESTRACJA");

	t->ustaw_nazwe("poprawna rejestracja");
	t->sprawdz_rownosc(1,1);

	t->ustaw_nazwe("niepoprawne rejestracja");
	t->sprawdz_czy_poprawna(true);

	zamknij_sekcje();

	otworz_sekcje("SPRAWDZ");

	t->ustaw_nazwe("sprawdz saldo");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("sprawdz kontakty");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("sprawdz historie");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("sprawdz kursy");
	t->sprawdz_czy_poprawna(true);

	zamknij_sekcje();

	otworz_sekcje("WYKONAJ");

	t->ustaw_nazwe("przelew");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("przelew do kontaktu");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("dodaj kontakt");
	t->sprawdz_czy_poprawna(true);

	t->ustaw_nazwe("wymiana walut");
	t->sprawdz_czy_poprawna(true);

	zamknij_sekcje();

	otworz_sekcje("WYLOGUJ");

	t->ustaw_nazwe("poprawne wylogowanie");
	t->sprawdz_czy_poprawna(true);

	zamknij_sekcje();
	
	cout << "=========================================== " << endl;
	printf("\x1B[32m 0 bledow : wszystkie testy zdane \033[0m \n");
	cout << "=========================================== " << endl;

	return false;
}

void otworz_sekcje(string _nazwa)
{
	cout << " --- " << _nazwa << " --------" << endl;
}

void zamknij_sekcje()
{
	cout << " ------------------------- " << endl << endl;
}