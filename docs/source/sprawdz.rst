Sprawdz
=============
Klasa Sprawdz istnieje w celu komunikacji 
klasy Ui z klasą Baza w momencie poproszenia przez 
użytkownika o wykonanie jakiejś operacji, 
która będzie odczytywać dane z plików. 

.. code-block:: c++
    :linenos:
    
    #pragma once
    #include "operacja.h"

    #include<iostream>

    using namespace std;

    class Sprawdz {
    public:
        Sprawdz();
        Operacja sprawdz(Operacja);
        Operacja wczytaj_stopka(Operacja);
    };