Operacja
=============
Klasa operacja jest wykorzystywana jako protokół komunikacji pomiędzy
aplikacją dla klienta a częścią serwerową. Pozwala na tworzenie zapytań do serwera
zwracanie danych oraz obsługę błędów. Pełni rolę protokołu komunikacyjnego
pomiędzy elementami naszej aplikacji.

.. code-block:: c++
   :linenos:

   class Operacja
    {
    public:
        string typ;
        string typ_operacji;
        string token;
        int kod_bledu;
        Dane* dane;
    };
   class Dane
    {
    public:
        vector <Historia> historia;
        vector <Kontakty> kontakty;
        Saldo saldo;
        Kurs kursy;
        Do_wykonania* do_wykonania;
    };
   class Do_wykonania
    {
    public:
        string nadawca;
        string adresat;
        double suma;
    };

Wytłumaczenie
^^^^^^^^^^^^^

.. toctree::
   :maxdepth: 2

   typ_operacji <typ_operacji>
   kod_bledu <kod_bledu>
