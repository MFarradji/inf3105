#include <iostream>
#include "dictionnaire.h"
#include "date.h"

using namespace std;

bool test1() {
  cout << "#### TEST 1 ########" << endl;
  bool echec = false;
  for (int n = 7; n <= 10; n++) {
    cout << "***** n=" << n << " *********" << endl;
    Dictionnaire<Date, string> d(n);
    d[Date(2017, 10, 29, 9, 30)] = "Examen1";
    d[Date(2017, 12, 17, 9, 30)] = "Examen2";
    d[Date(2017, 10, 16)] = "TP1";
    d[Date(2017, 11, 20)] = "TP2";
    d[Date(2017, 12, 21)] = "TP3";
    d[Date(2017, 12, 25)] = "Noël";
    cout << d[Date(2017, 10, 29, 9, 30)] << endl;
    
    if (d[Date(2017, 10, 29, 9, 30)] != "Examen1") {
      echec=false;
      cout <<" Echec!" << endl;
    }
    cout << d[Date(2017, 12, 17, 9, 30)] << endl;
    if (d[Date(2017, 12, 17, 9, 30)] != "Examen2") {
      echec=false;
      cout <<" Echec!" << endl;
    }
    cout << d[Date(2017, 10, 16)] << endl;
    if (d[Date(2017, 10, 16)] != "TP1")  {
      echec=false;
      cout <<" Echec!" << endl;
    }
    cout << d[Date(2017, 11, 20)] << endl;
    if (d[Date(2017, 11, 20)] != "TP2") {
      echec=false;
      cout <<" Echec!" << endl;
    }
    cout << d[Date(2017, 12, 21)] << endl;
    if (d[Date(2017, 12, 21)] != "TP3") {
      echec=false;
      cout <<" Echec!" << endl;
    }
    cout << d[Date(2017, 12, 25)] << endl;
    if (d[Date(2017, 12, 25)] != "Noël") {
      echec=false;
      cout <<" Echec!" << endl;
    }
  }
  cout << endl;
  return !echec;
}

void test2() {
  cout << "#### TEST 2 ########" << endl;
  {
    Dictionnaire<Date, int> d(20);
    // Ceci génère 10 dates espacées à toutes les 5 minutes à partir de 13h
    for (int i = 0; i < 10; i++) {
      int h = 13 + i * 5 / 60;
      int m = i * 5 % 60;
      d[Date(2017, 12, 7, h, m)] = i;
    }
    cout << "A. Nombre de tentatives: " << d.stats() << endl;
  }
  {
    Dictionnaire<Date, int> d(20);
    // Ceci génère 10 dates espacées à toutes les 10 minutes à partir de 13h
    for (int i = 0; i < 10; i++) {
      int h = 13 + i * 10 / 60;
      int m = i * 10 % 60;
      d[Date(2017, 12, 7, h, m)] = i;
    }
    cout << "B. Nombre de tentatives: " << d.stats() << endl;
  }
  {
    Dictionnaire<Date, int> d(20);
    // Ceci génère 10 dates espacées de 1 jour
    for (int i = 0; i < 10; i++) {
      d[Date(2017, (1 + i) / 31, (0 + i * 5) % 31)] = i;
    }
    cout << "C. Nombre de tentatives: " << d.stats() << endl;
  }

  cout << endl;
}

int main() {
  test1();
  test2();
  return 0;
}
