#include "wykonaj.h"
#include "baza.h"
#include "konto.h"
#include "zaloguj.h"

Wykonaj::Wykonaj()
{
}







Operacja Wykonaj::wykonaj(Operacja operacja)
{
	Baza baza = Baza();
	operacja = baza.zapis(operacja);
	return operacja;
}

