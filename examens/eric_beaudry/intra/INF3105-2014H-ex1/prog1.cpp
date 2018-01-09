/* prog1.cpp */
#include <iostream>
#include "fraction.h"

using namespace std;

void test(Fraction a, Fraction& b) {
  Fraction* c = new Fraction(a);
  a = b;
  b = *c;
  c = NULL;
  return;
}

int main() {
  Fraction f1(1,2), f2(2,3), f3(5,4);
  Fraction* tab = new Fraction[5];
  cout << endl;
  test(f1, tab[2]);
  test(tab[3], tab[4]);
  f3 = tab[5];
  cout << endl;
  return 0;
}
