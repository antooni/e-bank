Zaloguj 
=============
Zaloguj to klasa odpowiedzialna za logowanie, rejestrację oraz usuwanie kont.

.. code-block:: c++
    :linenos:

    class Zaloguj
    {
        string token;
        string baza;

    public:
        Zaloguj();
        
        string weryfikacja(string, string);
        string rejestracja(string, string, string, string);
        string wyloguj(string);
        bool usun_konto(string, string);

        string generuj_nr_konta();
        bool sprawdz_czy_w_bazie(string);
        void zapisz_do_bazy(string, string, string);
        void konfiguracja_bazy(string, string, string,string);
    };

Zawiera ona 4 główne metody:

weryfikacja()
^^^^^^^^^^^^^^
Pobiera dane użytkownika do zalogowania oraz sprawdza ich poprawność.

rejestracja()
^^^^^^^^^^^^^^
Po wyborze zarejestruj w panelu logowania funkcja pobiera dane do rejestracji i przypisuje mu unikalny wygenerowany numer konta.

wyloguj()
^^^^^^^^^^^^^^
Wylogowywuje użytkownika z sesji poprzez odebranie mu tokena sesji.

usun_konto()
^^^^^^^^^^^^^^   
Usuwa użytkownika z bazy logowania oraz porządkuje baze.