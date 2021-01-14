# e-bank
Bank internetowy. Repozytorium projektu na przedmiot Inżynieria Oprogramowania na III semestrze kierunku  Informatyki Technicznej na uczelni AGH

# Metodyka wytwarzania oprogramowania

# Wykorzystanie repozytorium

# Ciągła integracja

# Test-driven developement (TDD)
TDD jest to technika tworzenia oprogramowania, zaliczana do metod zwinnych, polega na:
- pisaniu testów sprawdzających daną funkcjonalność
- implementacji danej funkcjonalności do momentu przejścia testu
- refaktoryzacji kodu aby spełniał oczekiwane standardy

W jaki sposób wykorzystaliśmy TDD ?

Stworzyliśmy szkielet projektu, klas i metod, napisaliśmy testy, na początek wszystkie były negatywne :

![Alt text](/img/testy/errors-all.PNG?raw=true "Title")

Następnie stopniowo wdrażaliśmy kolejne funkcjonalności, tak aby przechodziły testy :

![Alt text](/img/testy/zaloguj-usun.PNG?raw=true "Title")

# Standardy kodowania

# Dokumentacja kodu
Dokumentacja generuje się automatycznie podczas każdego PR na gałąź dev (folder ./docs),
do automatyzacji tego procesu wykorzystano usługę "readthedocs" oraz narzędzie "sphinx".

Dokumentacja : https://e-bank.readthedocs.io/pl/latest/

# Inspekcja kodu, refaktoryzacja


