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

Operacja Sprawdz::wczytaj_stopka(Operacja operacja) {
    Baza baza = Baza();
    operacja = baza.wczytaj_stopka(operacja);

    return operacja;
}
