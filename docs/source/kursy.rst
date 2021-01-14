Kursy
=============
Plik kursy zawiera jeden wiersz z informacjami o kursach.
Istnieje tylko jeden taki plik na całą bazę.
Dane uszeregowane są w następujący sposób:
*zloty* *euro* *funt* *dolar*

Funkcja odczyt() jako argument przyjmuje obiekt klasy *operacja*. Służy ona głównie do oczytu danych o koncie klienta.

.. highlight:: cpp 
if(operacja.typ_operacji == "historia")

