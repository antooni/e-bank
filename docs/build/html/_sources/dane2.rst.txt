dane
==========
Klasa dane powstała w celu przechowywania aktualnie zczytanych danych z bazy oraz 
wykonywaniu operacji na nich. 

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

Pierwsze metody tej klasy wypisują wskazane przez użtykownika dane. 
Natomiast kolejne dwie:

.. code-block:: c++

    bool przewalutuj(string, string, double);

Otrzymuje dwie waluty, które mają zostać przetransferowane oraz ich wartość.
Funkcja zwraca true lub false.

.. code-block:: c++

    bool sprawdz_kwote(double, string);

Funkcja używana podczas przelewów oraz przewolutowywaniu sprawdza czy użytkownik 
posiada odpowiednie środki w celu wykonania operacji. Funkcja zwraca true lub false.
