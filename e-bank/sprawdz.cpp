#include "sprawdz.h"
#include "baza.h"

Sprawdz::Sprawdz()
{
}

Operacja Sprawdz::sprawdz(Operacja operacja)
{
    //cout << "sprawdzam" << endl;
    Baza baza = Baza();
    operacja = baza.odczyt(operacja);
    
    return operacja;
}
