#include <iostream>
#include <dodawanie.cpp>
#include <mnozenie.cpp>

using namespace std;

void funkcja(int,int,string);

int main(){
  string napis = "" // Antek dodaj napis
    
  funkcja(2,4,napis);  

  return 0;
}

void funkcja(int _a,int _b, string _napis)
{
    int wynik_dodawania = dodawanie(_a,_b); // Adam stworz funkcje dodawnie

    int wynik = mnozenie(_a, wynik_dodawania); //Adrian stworz funkcje mnozenie

    cout << _napis << wynik << endl;
}
