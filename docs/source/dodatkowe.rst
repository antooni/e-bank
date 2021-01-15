Dodatkowe
=============
Plik dodatkowe został w celu przetrzymwania struktur danych za pomocą klas 
w celu przechowywania danych w obiekcie *operacja*. 

Zawiera on następujące struktury: 

.. code-block:: c++
    :linenos:

    class Data {
        ...
    };

    class Historia {
        ...
    };

    class Kontakty {
        ...
    };

    class Saldo {
        ...
    };

    class Kurs {
        ...
    };

Dzięki temu plikowi poprzez stworzenie jednego z powyższych obiektów
możemy operować większą strukturą danych. Przykładowo klasa Saldo zawiera 
4 zmienne typu double takie jak: *zloty*, *euro*, *dolar*, *funt*.