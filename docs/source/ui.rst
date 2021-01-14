Ui 
=============
Ui to klasa, która odpowiada za bezpośredni połączenie między interfejsem a użytkownikiem.
Jej zadaniem jest wyświetlić informacje od użytkownika, pobrać dane oraz je zwalidować.
Na podstawie wyboru użytkownika wywołuje ona odpowiednie metody swoich obiektów w celu przeprowadzenia danej operacji.

.. code-block:: c++
    :linenos:

    class UI
    {
        string token;
        Konto* konto;
        Uzytkownik* user;
        Zaloguj* zaloguj;
        bool test;

        int przelew(Operacja, string, double, string);
    
        bool obsluga_rejestracji_lub_logowania();
        void obsluga_operacji_lub_wylogowania();

    public:
        UI();
        void start();
    };

obsluga_rejestracji_lub_logowania()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Wyświetla w konsoli opcje dla niezalogowanego użytkownika. Po wyborze oraz podaniu 
niezbędnych danych wywołuje odpowiednio funkcje weryfikacja() lub rejestracja().


obsluga_operacji_lub_wylogowania()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Wyświetla w konsoli opcje dla zalogowanego uzytkownika. Po wyborze przechodzi odpowiednio do 
metod sprawdzania lub wykonania.

przelew()
^^^^^^^^^^^
Główna metoda bankowa umożliwiająca transakcje pomiędzy kontami.
Jej głównym zadaniem jest walidacja danych podczas wyboru przelewu oraz wywołanie odpowiednich funkcji, 
które dokonają przekazania pieniędzy na odpowiednie konto.
