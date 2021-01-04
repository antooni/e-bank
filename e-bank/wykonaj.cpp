#include "wykonaj.h"
#include "baza.h"

Wykonaj::Wykonaj()
{
}

Operacja Wykonaj::wykonaj(Operacja operacja)
{

	//cout << "wykonuje" << endl;
	if (operacja.dane->saldo < operacja.dane->do_wykonania->suma)
	{
		// ustaw blad
		return operacja;
	}
	else
	{
		Baza baza = Baza();
		operacja = baza.zapis(operacja);
		return operacja;
	}
	
}
