/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Copie de pointeur et gestion de mémoire
*/

#include <iostream>

#include "point.hpp"
#include "rectangle.hpp"

using namespace std;

int main() {
  Rectangle* r1 = new Rectangle();
  Rectangle* r2 = new Rectangle(Point(0, 0), Point(10, 10));
  Rectangle* r3 = new Rectangle();
  *r3 = *r2;
  delete r1;
  r1 = r3;
  delete r2;
  delete r3;
}
