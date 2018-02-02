/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
*/

#include <iostream>
#include <stdlib.h>
#include "pile.h"

using namespace std;

void test1();
void test2();

int main() {
  test1();
  test2();
  return 0;
}

void test1() {
  cout << "Test #1 : Test de la pile (opérations de base)" << endl;
  Pile<int> pile1;
  pile1.empiler(1);
  pile1.empiler(4);
  pile1.empiler(2);
  if (pile1.depiler() != 2)
      cout << "1 >> Erreur" << endl;
  if (pile1.depiler() != 4)
      cout << "2 >> Erreur" << endl;
  if (pile1.depiler() != 1)
      cout << "3 >> Erreur" << endl;
  if (!pile1.vide())
      cout << "4 >> Erreur" << endl;

  pile1.empiler(13);
  if (pile1.vide())
      cout << "5 >> Erreur" << endl;
  if (pile1.depiler() != 13)
      cout << "6 >> Erreur" << endl;
  if (!pile1.vide())
      cout << "7 >> Erreur" << endl;

  Pile<int> pile2;
  pile2.empiler(13);
  if (pile2.vide())
      cout << "8 >> Erreur" << endl;
  if (pile2.depiler() != 13)
      cout << "9 >> Erreur" << endl;
  if (!pile2.vide())
      cout << "10 >> Erreur" << endl;
  cout << "-------- Fin #1 --------------" << endl;
}

void test2() {
  cout << "Test #2 : Test de la pile (opérateur =)" << endl;
  Pile<int> pile1;
  pile1.empiler(1);
  pile1.empiler(4);
  pile1.empiler(2);
  Pile<int> pile2;
  pile2.empiler(20);
  pile2.empiler(21);
  pile2 = pile1;
  pile1.empiler(10);
  if (pile1.depiler() != 10)
      cout << "1 >> Erreur" << endl;
  if (pile1.depiler() != 2)
      cout << "2 >> Erreur" << endl;
  if (pile1.depiler() != 4)
      cout << "3 >> Erreur" << endl;
  if (pile1.vide())
      cout << "4 >> Erreur" << endl;
  pile2 = pile1;
  if (pile2.depiler() != 1)
      cout << "5 >> Erreur" << endl;
  if (!pile2.vide())
      cout << "6 >> Erreur" << endl;
  if (pile1.vide())
      cout << "7 >> Erreur" << endl;
  
  cout << "-------- Fin #2 --------------" << endl;
}
