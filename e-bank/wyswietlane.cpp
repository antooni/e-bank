#include "wyswietlane.h"



void menu() {
	cout.width(60);
	cout << "Aby sie zalogowac wybierz 1" << endl << endl;
	cout.width(64);
	cout << "Aby sie zarejestrowac wybierz 2" << endl << endl;
	cout.width(56);
	cout << "Aby zakonczyc wybierz 3" << endl << endl;
}

void menu_sprawdz() {
	cout.width(62);
	cout << "Aby sprawdzic saldo wybierz 1" << endl << endl;
	cout.width(64);
	cout << "Aby sprawdzic kontaky wybierz 2" << endl << endl;
	cout.width(65);
	cout << "Aby sprawdzic historie wybierz 3" << endl << endl;
	cout.width(68);
	cout << "Aby sprawdzic kursy walut wybierz 4" << endl << endl;
	cout.width(53);
	cout << "Aby wrocic wybierz 0" << endl << endl;
}

void menu_wykonaj() {
	cout.width(62);
	cout << "Aby wykonac dowolny przelew 1" << endl << endl;
	cout.width(69);
	cout << "Aby wykonac przelew do kontrahenta 2" << endl << endl;
	cout.width(57);
	cout << "Aby dodac nowy kontakt 3" << endl << endl;
	cout.width(54);
	cout << "Aby wymienic waluty 4" << endl << endl;
}

void menu_operacji() {
	cout.width(61);
	cout << "Aby sprawdzic dane wybierz 1" << endl << endl;
	cout.width(63);
	cout << "Aby wykonac operacje wybierz 2" << endl << endl;
	cout.width(60);
	cout << "Aby wylogowac sie wybierz 3" << endl << endl;
}