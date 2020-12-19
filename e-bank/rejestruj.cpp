#include "rejestruj.h"

void rejestruj()
{
	string login, haslo, phaslo;
	cout << "Podaj jaki chcesz miec login:" << endl;
	cin >> login;
					//wywolac funkcje sprawdz czy login juz istenieje w pliku
	/*if(login istnieje){
		cout << "Podany login juz istnieje" << endl;
		break;
	}*/
	
	cout << "Podaj jakie chcesz miec haslo" << endl;
	cin >> haslo;
	cout << "Powtorz haslo" << endl;
	cin >> phaslo;
	if (haslo != phaslo) {
		cout << "Powtorzone haslo jest bledne" << endl;
	}
	else {
		cout << "Pomyslnie zarejestrowano" << endl;
		cout << "Witamy w naszym banku mozesz sie teraz zalogowac" << endl;	//mozna by dorzucic tu przeniesienie do logowania od razu
								//wykonanie samego zarejestrowania wpisanie do pliku
	}
}
