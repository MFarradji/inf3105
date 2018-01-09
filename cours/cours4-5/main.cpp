#include <iostream>
#include "Fraction.hpp"

using namespace std;

Fraction exemple() {
  Fraction f1(3, 4);
  /*
  Fraction* pf = new Fraction(5, 6);
  Fraction f2 = f1; // appel le constructeur par copie si l'opérateur = n'est pas défini
  cout << *pf << endl;
  cout << f2 << endl;
  delete pf;
  */
  return f1; // appel le constructeur par copie
}

int main() {
  // Fraction f1(1, 2);
  // cout << f1 << endl;
  Fraction fraction = exemple();
  cout << fraction << endl;
}
