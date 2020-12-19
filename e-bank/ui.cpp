#include "ui.h"
#include "zaloguj.h"
#include "rejestruj.h"

void str_startowa() {
	system("cls");
	cout << "Wybierz funkcje ktora chcesz wykonac (wpisz 1 lub 2 lub 3 aby wyjsc)" << std::endl;
	cout << "1 Zaloguj" << endl;
	cout << "2 Zarejestruj" << endl;
	cout << "3 Wyjdz" << endl;

}

void uruchom()
{
	int wybor;

	Zaloguj zaloguj("baza.txt");

	for (;;) {
		str_startowa();
		cin >> wybor;
		switch (wybor){
		case 1:			//jesli wybrano zaloguj		
			if (zaloguj.sprawdz("Antoni", "Pawlak"))
			{
				cout << "zalogowano" << endl;
			}

			break;
		case 2:			//jesli wybrano rejestruj
			rejestruj();			//wywolanei funkcji do resjestracji   
			break;


		default:
			break;
		}
		if (wybor == 3) {
			break;
		}
		cin >> wybor;


	}
}
