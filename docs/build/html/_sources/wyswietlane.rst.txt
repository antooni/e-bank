Wyswietlane
==============
Plik wyswietlane.cpp zawiera główne funkcje wywoływane przez klasę Ui odpowiadające za 
kontakt z klientem. Zawiera wszelkie menu oraz funkcje wczytywania hasła.

.. code-block:: c++
    :linenos:
    
    void menu();
    void menu_sprawdz();
    void menu_wykonaj();
    void menu_operacji();
    void podaj_dane_login(string& email, string& haslo);
    void podan_dane_rejestruj(string& email, string& imie, string& haslo, string& nazwisko);
    void stopka(Operacja operacja, int saldo);
    void wczytaj_haslo(string& haslo);

