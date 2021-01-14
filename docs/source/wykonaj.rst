Wykonaj
=============
Klasa Wykonaj istnieje w celu komunikacji 
klasy Ui z klasą Baza w momencie poproszenia przez 
użytkownika o wykonanie jakiejś operacji, 
która będzie aktualizowała aktualne dane w plikach. 

.. code-block:: c++
    :linenos:
    
    #pragma once
    #include "operacja.h"

    #include<iostream>

    using namespace std;

    class Wykonaj {
    public:
        Wykonaj();
        Operacja wykonaj(Operacja);
    };