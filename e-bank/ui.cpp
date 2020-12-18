#include "ui.h"

void str_startowa() {
	system("cls");
	std::cout << "Wybierz funkcje ktora chcesz wykonaæ (wpisz 1 lub 2)" << std::endl;
	std::cout << "1 Zaloguj" << std::endl;
	std::cout << "2 Zarejestruj" << std::endl;
}

void uruchom()
{
	int wybor;

	for (;;) {
		str_startowa();
		cin >> wybor;
		switch (wybor){
		case 1:			//jesli wybrano zaloguj		
						//wywolanie funkcji zaloguj   ma zwracac bool czy sie udalo
			break;
		case 2:			//jesli wybrano rejestruj
						//wywolanei funkcji do resjestracji   niech zwraca czy sie udalo zarejestrowac
			break;

		default:
			break;
		}
						
						//dalszy kod jesli uda zalogowac


	}
}
