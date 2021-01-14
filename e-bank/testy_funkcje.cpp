#include "testy.h"


bool test_poprawne_logowanie(string _nazwa, string _haslo)
{
	Zaloguj* zaloguj = new Zaloguj;
	string token = "";
	token = zaloguj->weryfikacja(_nazwa, to_string(hash<string>{}(_haslo)));

	if (token == "") return false;
	return true;
}


bool test_poprawna_rejestracja(string nazwa, string haslo, string imie, string nazwisko)
{
	Zaloguj* zaloguj = new Zaloguj;
	string token = "";
	token = zaloguj->rejestracja(nazwa, to_string(hash<string>{}(haslo)), imie, nazwisko);

	if (token == "") return false;

	return true;
}

bool test_poprawne_wylogowanie(string _nazwa, string _haslo)
{
	Zaloguj* zaloguj = new Zaloguj;
	string token = "";
	token = zaloguj->weryfikacja(_nazwa, to_string(hash<string>{}(_haslo)));

	if (token == "") return false;
	return true;

	token = zaloguj->wyloguj(token);
	if (token == "") return true;
	return false;
}

bool test_usuwanie_konta(string nazwa, string haslo)
{
	Zaloguj* zaloguj = new Zaloguj;
	bool res = false;

	res = zaloguj->usun_konto(nazwa, to_string(hash<string>{}(haslo)));

	return res;

}

bool test_saldo()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "saldo";

	operacja = konto->sprawdz(operacja);
	if (operacja.dane->saldo->zloty == double(0)) return true;

	return false;
}

bool test_kontakty()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "kontakty";

	operacja = konto->sprawdz(operacja);
	if (operacja.dane->kontakty[0].imie != "Sebastian") return false;
	if (operacja.dane->kontakty[0].nazwisko != "Werecki") return false;
	if (operacja.dane->kontakty[0].numer_konta != "38547035") return false;
	if (operacja.dane->kontakty[0].numer != "1") return false;

	return true;
}

bool test_historia()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "historia";

	operacja = konto->sprawdz(operacja);
	if (operacja.dane->historia[0].nadawca != "41711555") return false;
	if (operacja.dane->historia[0].odbiorca != "03700877") return false;
	if (operacja.dane->historia[0].wartosc != double(-300)) return false;
	if (operacja.dane->historia[0].waluta != "PLN") return false;

	return true;
}

bool test_kursy()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "kurs";

	operacja = konto->sprawdz(operacja);
	if (operacja.dane->kurs->euro != 4.52) return false;

	return true;
}

bool test_przelew()
{

	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "zapisz_saldo";
	operacja.dane->saldo->zloty = 100;
	operacja.dane->saldo->euro = 50;
	operacja.dane->saldo->funt = 300;
	operacja.dane->saldo->dolar = 200;

	konto->wykonaj(operacja);

	UI* ui = new UI;
	ui->zaloguj = new Zaloguj;
	ui->przelew(operacja, "40974313", 100, "P");

	operacja.typ = "sprawdz";
	operacja.typ_operacji = "saldo";

	if (operacja.dane->saldo->zloty == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool test_przelew_do_kontaktu()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "zapisz_saldo";
	operacja.dane->saldo->zloty = 100;
	operacja.dane->saldo->euro = 50;
	operacja.dane->saldo->funt = 300;
	operacja.dane->saldo->dolar = 200;

	konto->wykonaj(operacja);

	UI* ui = new UI;
	ui->zaloguj = new Zaloguj;

	operacja.typ_operacji = "kontakty";
	konto->sprawdz(operacja);
	
	ui->przelew(operacja, operacja.dane->kontakty[1].numer_konta, 100, "P");


	if (operacja.dane->saldo->zloty == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool test_dodaj_kontakt()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();


	operacja.typ_operacji = "kontakty";

	operacja.dane->kontakty.clear();
	konto->sprawdz(operacja);

	operacja.dane->do_wykonania->kontakty.imie = "admin";
	operacja.dane->do_wykonania->kontakty.imie = "admin";
	operacja.dane->do_wykonania->kontakty.numer_konta = "40974313";

	
	operacja.dane->do_wykonania->kontakty.numer = to_string(operacja.dane->kontakty.size() + 1);
	int ilosc_kontaktow = operacja.dane->kontakty.size() + 1;

	operacja.typ_operacji = "zapisz_kontakt";
	konto->wykonaj(operacja);

	operacja.typ_operacji = "kontakty";

	operacja.dane->kontakty.clear();
	konto->sprawdz(operacja);

	if (operacja.dane->kontakty.size() == ilosc_kontaktow) {
		operacja.dane->kontakty.clear();
		return true;
	}
	return false;

}

bool test_wymien_walute()
{
	string token = "41711555";
	Operacja operacja = Operacja();
	Konto* konto = new Konto();

	operacja.token = token;
	operacja.typ = "sprawdz";
	operacja.typ_operacji = "zapisz_saldo";
	operacja.dane->saldo->zloty = 0;
	operacja.dane->saldo->euro = 100;
	operacja.dane->saldo->funt = 300;
	operacja.dane->saldo->dolar = 200;

	konto->wykonaj(operacja);
	operacja.typ_operacji = "kurs";
	konto->sprawdz(operacja);

	UI* ui = new UI;
	ui->zaloguj = new Zaloguj;

	if (operacja.dane->przewalutuj("E", "U", 100)) {
		operacja.typ_operacji = "zapisz_saldo";
		konto->wykonaj(operacja);
	}

	if (operacja.dane->saldo->euro != 0) return false;
	if (operacja.dane->saldo->dolar != (200.0 + 100.0 * 4.52 / 3.71)) return false;
	return true;
		//saldo->dolar += ((suma * kurs->euro) / kurs->dolar);
	
}
