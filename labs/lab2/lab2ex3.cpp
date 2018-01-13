/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Type de passage de paramètres
*/

#include <iostream>

using namespace std;

void test(int a, int* b, int* c, int& d, int*& e) {
  a = 11; // effet local
  b++; // change l'adresse locale de b
  *c = 13; // change la valeur pointée par c
  d = 14; // change la valeur référée par d
  e = c; // change la valeur du pointeur (adresse) pour celle de c
}

int main() {
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;
  int* p5 = &v1;
  test(v1, &v2, &v3, v4, p5);
  cout << v1 << " " << v2 << " " << v3 << " " << v4 << " " << *p5 << " " << endl;
  return 0;
}
