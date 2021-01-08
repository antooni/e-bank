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
				historia.data.dzien = stoi(temp);
				iss >> temp;
				historia.data.miesiac = stoi(temp);
				iss >> temp;
				historia.data.rok = stoi(temp);
				iss >> temp;
				historia.wartosc = stod(temp);
				iss >> temp;
				historia.odbiorca = temp;
				iss >> temp;
				historia.nadawca = temp;
				operacja.dane->historia.push_back(historia);
			}
			plik.close();
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
				iss >> kontakty.imie;
				iss >> kontakty.nazwisko;
				iss >> kontakty.numer_konta;
				operacja.dane->kontakty.push_back(kontakty);
			}
			plik.close();
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
			istringstream iss(line);

			iss >> temp;
			operacja.dane->saldo.zloty = stod(temp);
			iss >> temp;
			operacja.dane->saldo.euro = stod(temp);
			iss >> temp;
			operacja.dane->saldo.funt = stod(temp);
			iss >> temp;
			operacja.dane->saldo.dolar = stod(temp);
			plik.close();
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	else if (operacja.typ_operacji == "kursy") {
		string line;
		string temp;
		fstream plik;
		plik.open("base/kursy.txt", ios::in | ios::out);
		if (plik.good() == true)
		{
			getline(plik, line);
			istringstream iss(line);
			iss >> temp;
			operacja.dane->kursy.zloty = stod(temp);
			iss >> temp;
			operacja.dane->kursy.euro = stod(temp);
			iss >> temp;
			operacja.dane->kursy.funt = stod(temp);
			iss >> temp;
			operacja.dane->kursy.dolar = stod(temp);
			plik.close();
		}
		else {
			operacja.kod_bledu = 1;
		}
	}

	return operacja;
}

Operacja Baza::zapis(Operacja operacja)
{
	//otworz odpowiedni plik
	//zmodyfikuj lub dodaj nowy rekord

	// ustaw blad 
	return operacja;
}
