/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
*/

#include <iostream>
#include "pile.h"

void fonction1(Pile<int> pile, int a) {
  pile.empiler(a);
  pile.afficher();
}

int main() {
  Pile<int> pile1;
  pile1.empiler(5);
  pile1.empiler(2);
  pile1.empiler(7);
  pile1.empiler(1);
  pile1.afficher();

  Pile<int> pile2;
  pile2.empiler(1);
  pile2.empiler(2);
  fonction1(pile2, 3);
  fonction1(pile2, 4);
  fonction1(pile2, 5);
  pile2.afficher();
  return 0;
}
