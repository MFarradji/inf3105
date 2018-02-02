/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
*/

#include <iostream>
#include "pile.h"

int main() {
  int n = 0;
  while (true) {
    cout << (n++) << " ";
    Pile<int> pile1;
    for (int i = 0; i < 100000; i++)
      pile1.empiler(i);
    Pile<int> pile2 = pile1;
    pile1.vider();

    Pile<int> pile3;
    pile3.empiler(10);
    pile3 = pile2;
    pile3 = pile1;
  }
}
