# e-bank
Repozytorium projektu na przedmiot Inżynieria Oprogramowania na III semestrze kierunku  Informatyki Technicznej na uczelni AGH

# Metodyka wytwarzania oprogramowania

# Wykorzystanie repozytorium
Repozytorium kodu to narzędzie programisty, umożliwiające automatyczne wykrywanie zmian w plikach i automatyczne dokonywanie aktualizacji. Każdy update repozytorium kodu jest opisywany wiadomością, a historia zmian oraz ich autorzy są odpowiednio wyszczególnieni. Dzięki temu możliwe jest łatwe znalezienie potencjalnie występujących problemów oraz przywrócenie kodu do poprzedniego stanu. Wykorzystanie repozytorium dodatkowo sprzyja pracy w zespole, ułatwia podział projektu na mniejsze bezkolizyjne części.

**Wykorzystany system kontroli wersji : Git**
Git to darmowy, rozproszony system kontroli wersji o otwartym kodzie źródłowym, zaprojektowany do obsługi wszystkiego, od małych do bardzo dużych projektów, szybko i wydajnie. Pozwala na tworzenie gałęzi oraz ich łaczenie, umożliwia prace offline, posiada pełne wsparcie dla obecnych protokołów sieciowych (np. HTTP). Co najważniejsze, nie zapamiętuje zmian pomiędzy kolejnymi wersjami kodu, a całe ich obrazy (snapshots).  

![Alt text](/img/graphics/git-logo.png?raw=true "Title")

**Wykorzystane zdalne repozytorium Git : github.com**
Github to hostingowy serwis internetowy przeznaczony dla projektów programistycznych wykorzystujący system kontroli wersji Git. Pozwala na synchronizacje repozytorium pomiędzy kilkoma deweloperami, pobieranie oraz publikowanie kodu, pull request'y, oraz webhooki (wykrozystany do automatycznego budowania dokumantacji). Dodatkowo serwis jest darmowy dla zwykłych użytkowników oraz posiada bardzo dobrą dokumentację. Jest to obecnie najpopularniszy serwis do hostingu repozytorium.

![Alt text](/img/graphics/github-logo.jpg?raw=true "Title")

**W jaki sposób wykorzystaliśmy repozytorium ?**


# Ciągła integracja

# Test-driven developement (TDD)
TDD jest to technika tworzenia oprogramowania, zaliczana do metod zwinnych, polega na:
- pisaniu testów sprawdzających daną funkcjonalność
- implementacji danej funkcjonalności do momentu przejścia testu
- refaktoryzacji kodu aby spełniał oczekiwane standardy

![Alt text](https://marsner.com/wp-content/uploads/test-driven-development-TDD.png?raw=true)

**W jaki sposób wykorzystaliśmy TDD ?**

**Stworzyliśmy szkielet projektu, klas i metod, napisaliśmy testy, na początek wszystkie były negatywne :**

![Alt text](/img/testy/errors-all.PNG?raw=true "Title")

**Następnie stopniowo wdrażaliśmy kolejne funkcjonalności, tak aby przechodziły testy :**

![Alt text](/img/testy/zaloguj-usun.PNG?raw=true "Title")

**Na koniec procesu wytwarzania oprogramowania wszystkie testy zostały zdane :**

![Alt text](/img/testy/no-errors.PNG?raw=true "Title")

**Dodatkowe założenia i wnioski**
- implementacja musi przechodzić test jednostkowy
- po przejściu testu jednostkowego następowała refaktoryzacja kodu
- wykorzystanie testów usprawniło iteracyjne wytwarzanie oprogramowania
- metodyka testowania pozwoliła na uniknięcie wielu niechcianych błędów

# Standardy kodowania

# Dokumentacja kodu
Dokumentacja generuje się automatycznie podczas każdego PR na gałąź dev (folder ./docs),
do automatyzacji tego procesu wykorzystano usługę "readthedocs" oraz narzędzie "sphinx".

Dokumentacja : https://e-bank.readthedocs.io/pl/latest/

# Inspekcja kodu, refaktoryzacja


