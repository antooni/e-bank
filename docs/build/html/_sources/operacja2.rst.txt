operacja
===========
Obiekt operacja jest głównym obiektem poruszającym się po funkcjach i obiektach oraz przechowującym 
tymczasowe dane dotyczące użytkownika.

typ_operacji
--------------

"sprawdz"
""""""""""
- ``"saldo"`` - dane salda z bazy zapisywane są do operacja.dane->saldo.euro/funt/zloty/dolar
- ``"historia"`` - dane historii z bazy zapisywane są do operacja.dane->historia (vector, który w każdym wierszu ma kolejne rekordy historii)
- ``"kontakty"`` - dane kontaków z bazy zapisywane są do operacja.dane->kontakty (vector, który w każdym wierszu ma kolejne rekordy kontaktów)
- ``"kurs"`` - dane kursów są zczytywane z bazy i zapisane do operacja.dane->kursy.euro/funt/zloty/dolar

"wykonaj"
""""""""""
- ``"dowolny przelew"`` - użytkownik podaje dowolny numer bankowy, kwote oraz walute. Jeżeli dany numer znajduje się w naszej bazie to przelew robiony jest *"wewnetrznie"*, to znaczy zapisywany jest saldo oraz historia są zmieniane u odbiorcy i nadawcy. Natomiast gdy przelew jest *"zewnętrzny"* to aktualizowane jest tylko saldo i historia nadawcy, a operacja dodatkowo zapisuje się w przelewach zewnętrznych
- ``"przelew do kontaktu"`` - użykownik wybiera id swojego kontaktu, wpisuje kwote i walute. Jeżeli środki na koncie się zgadzają, to przelew wykonywany jest do danego kontaktu.
- ``"dodaj nowy kontakt"`` - użykownik wprowadza imie, nazwisko oraz numer kontaktu
- ``"przewalutowanie"`` - użykownik wybiera symbol walut do przewalutowania oraz kwote. Jeżeli ma tyle środków, to kwota zostanie przewalutowana 

kod_bledu
------------

- ``0`` - brak błędów
- ``1`` - błąd otwarcia plików
- ``2`` - brak środków na koncie

token
-------------

- specjalna zmienna przechowująca *token* użytkownika. Tylko zalogowani użytkownicy otrzymują swój token.


