#include "wykonaj.h"
#include "baza.h"
#include "konto.h"
#include "zaloguj.h"

Wykonaj::Wykonaj()
{
}







Operacja Wykonaj::wykonaj(Operacja operacja)
{

	//cout << "wykonuje" << endl;
	//if (operacja.dane->saldo < operacja.dane->do_wykonania->suma)
	//{
	//	// ustaw blad
	//	return operacja;
	//}
	//else
	//{
	//	Baza baza = Baza();
	//	operacja = baza.zapis(operacja);
	//	return operacja;
	//}
	Baza baza = Baza();
	operacja = baza.zapis(operacja);
	return operacja;
}

/*bool Wykonaj::poprawnosc_sumy(double suma, Operacja operacja, Konto* konto) {
	konto->sprawdz(operacja);
	if (suma <= operacja.dane->saldo->zloty) {
		return true;
	}
	else {
		return false;
	}
}*/
