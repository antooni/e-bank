#pragma once
#include "baza.h"




Baza::Baza()
{
}
Operacja Baza::odczyt(Operacja operacja)
{	
	if (operacja.typ_operacji == "historia") {
		Historia historia;
		string line;
		string temp;
		fstream plik;
		plik.open("base/" + operacja.token + "/historia.txt", ios::in | ios::out);
		if (plik.good() == true)
		{
			while (getline(plik, line))
			{
				istringstream iss(line);
				iss >> temp;
				historia.data.dzien = temp;
				iss >> temp;
				historia.data.miesiac = temp;
				iss >> temp;
				historia.data.rok = temp;
				iss >> temp;
				historia.wartosc = stod(temp);
				iss >> temp;
				historia.waluta = temp;
				iss >> temp;
				historia.odbiorca = temp;
				iss >> temp;
				historia.nadawca = temp;
				operacja.dane->historia.push_back(historia);
			}
			plik.close();
			operacja.kod_bledu = 0;
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	else if (operacja.typ_operacji == "kontakty") {
		Kontakty kontakty;
		string line;
		fstream plik;
		plik.open("base/" + operacja.token + "/kontakty.txt", ios::in | ios::out);
		if (plik.good() == true)
		{
			while (getline(plik, line))
			{
				istringstream iss(line);
				iss >> kontakty.numer;
				iss >> kontakty.imie;
				iss >> kontakty.nazwisko;
				iss >> kontakty.numer_konta;
				operacja.dane->kontakty.push_back(kontakty);
			}
			plik.close();
			operacja.kod_bledu = 0;
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	else if (operacja.typ_operacji == "saldo") {
		string line;
		string temp;
		fstream plik;
		plik.open("base/" + operacja.token + "/saldo.txt", ios::in | ios::out);
		if (plik.good() == true)
		{
			
			getline(plik, line);
			operacja.dane->saldo->zloty = stod(line);
			//operacja.dane->saldo.zloty = stod(temp);
			getline(plik, line);
			operacja.dane->saldo->euro = stod(line);
			//operacja.dane->saldo.euro = stod(temp);
			getline(plik, line);
			operacja.dane->saldo->funt = stod(line);
			//operacja.dane->saldo.funt = stod(temp);
			getline(plik, line);
			operacja.dane->saldo->dolar = stod(line);
			//operacja.dane->saldo.dolar = stod(temp);
			plik.close();
			operacja.kod_bledu = 0;
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	else if (operacja.typ_operacji == "kurs") {
		string line;
		string temp;
		fstream plik;
		plik.open("base/kursy.txt", ios::in | ios::out);
		if (plik.good() == true)
		{
			getline(plik, line);
			istringstream iss(line);
			iss >> temp;
			operacja.dane->kurs->zloty = stod(temp);
			iss >> temp;
			operacja.dane->kurs->euro = stod(temp);
			iss >> temp;
			operacja.dane->kurs->funt = stod(temp);
			iss >> temp;
			operacja.dane->kurs->dolar = stod(temp);
			plik.close();
			operacja.kod_bledu = 0;
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	return operacja;
}

Operacja Baza::zapis(Operacja operacja)
{
	if (operacja.typ_operacji == "zapisz_kontakt") {
		fstream zapisz;
		zapisz.open("base/" + operacja.token + "/kontakty.txt", ios::out | ios::app);
		zapisz.seekg(0, ios::end);
		if (zapisz.tellg() != 0) { zapisz << endl; }
		zapisz << operacja.dane->do_wykonania->kontakty.numer << " " << operacja.dane->do_wykonania->kontakty.imie << " " << operacja.dane->do_wykonania->kontakty.nazwisko << " " << operacja.dane->do_wykonania->kontakty.numer_konta;

		zapisz.close();
	}

	else if (operacja.typ_operacji == "zapisz_saldo") {
		ofstream zapisz;
		zapisz.open("base/" + operacja.token + "/saldo.txt", ios::trunc);
		zapisz << operacja.dane->saldo->zloty << endl << operacja.dane->saldo->euro << endl << operacja.dane->saldo->funt << endl << operacja.dane->saldo->dolar;

		zapisz.close();
	}

	else if (operacja.typ_operacji == "zapisz_historie") {
		fstream zapisz;
		zapisz.open("base/" + operacja.token + "/historia.txt", ios_base::out | ios_base::app);
		if (zapisz.good()) {
			zapisz.seekg(0, ios::end);
			if (zapisz.tellg() != 0) { zapisz << endl; }
			zapisz << operacja.dane->do_wykonania->historia.data.dzien << " "
				<< operacja.dane->do_wykonania->historia.data.miesiac << " "
				<< operacja.dane->do_wykonania->historia.data.rok << " "
				<< operacja.dane->do_wykonania->historia.wartosc << " "
				<< operacja.dane->do_wykonania->historia.waluta << " "
				<< operacja.dane->do_wykonania->historia.odbiorca << " "
				<< operacja.dane->do_wykonania->historia.nadawca;
			zapisz.close();
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	else if (operacja.typ_operacji == "przelew zewnetrzny") {
		fstream zapisz;
		zapisz.open("base/przelewy_zewnetrzne.txt", ios_base::out | ios_base::app);
		if (zapisz.good()) {
			zapisz.seekg(0, ios::end);
			if (zapisz.tellg() != 0) { zapisz << endl; }
			zapisz << operacja.dane->do_wykonania->historia.wartosc << " "
				<< operacja.dane->do_wykonania->historia.waluta << " "
				<< operacja.dane->do_wykonania->historia.odbiorca << " "
				<< operacja.dane->do_wykonania->historia.nadawca;
		}
	}
	return operacja;
}


Operacja Baza::wczytaj_stopka(Operacja operacja) {

	string line;
	string temp;
	fstream plik;
	plik.open("base/" + operacja.token + "/dane.txt", ios::in | ios::out);
	if (plik.good() == true)
	{
		getline(plik, line);
		istringstream iss(line);
		iss >> temp;
		operacja.dane->uzytkownik->imie = temp;
		iss >> temp;
		operacja.dane->uzytkownik->nazwisko = temp;
		iss >> temp;
		operacja.dane->uzytkownik->email = temp;
		iss >> temp;
		operacja.dane->uzytkownik->numer_konta = temp;
		plik.close();
		operacja.kod_bledu = 0;
	}
	else {
		operacja.kod_bledu = 1;
	}
	return operacja;
}
