Operacja
=============
Klasa operacja jest wykorzystywana jako protokół komunikacji pomiędzy
aplikacją dla klienta a częścią serwerową. Pozwala na tworzenie zapytań do serwera
zwracanie danych oraz obsługę błędów. Pełni rolę protokołu komunikacyjnego
pomiędzy elementami naszej aplikacji.


.. toctree::
   :maxdepth: 2

   operacja <operacja2>

.. code-block:: c++
   :linenos:

   class Operacja
   {
   public:
      string typ_operacji;
      string token;
      int kod_bledu;
      Dane* dane;
      Do_wykonania* do_wykonania;
      Operacja();
   };


.. toctree::
   :maxdepth: 2

   do_wykonania <do_wykonania>

.. code-block:: c++
   :linenos:

   class Do_wykonania
   {
   public:
      Historia historia;
      Kontakty kontakty;
      Saldo saldo;
      double suma = 0;
      string odbiorca;
      Do_wykonania();
   };


.. toctree::
   :maxdepth: 2

   dane <dane2>

.. code-block:: c++
   :linenos:

   class Dane
   {
   public:
      vector <Historia> historia;
      vector <Kontakty> kontakty;
      Saldo* saldo;
      Kurs* kurs;
      Do_wykonania* do_wykonania;
      Uzytkownik* uzytkownik;
      string znajdz_numer(string);
      void wypisz_saldo();
      void wypisz_kontakty();
      void wypisz_historia();
      void wypisz_kurs();
      bool przewalutuj(string, string, double);
      bool sprawdz_kwote(double suma, string waluta);
      Dane();
   };



