do_wykonania
================
Klasa do_wykonania powstała w celu ułożenia danych oraz przesłania ich do bazy 
podczas gdy ma wykonać się ich zapis. Zawiera ona strukturę historii, kontaktów oraz salda.

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