#include <iostream>

using namespace std;

int factorielle(int n) {
  int resultat = 1;
  if (n != 0)
    resultat= n * factorielle(n - 1);
  return resultat;
}

int fibonnaci(int n) {
  if (n < 2)
     return n;
   else
     return fibonnaci(n - 1) + fibonnaci(n - 2);
}

int main() {
  int nombre = 4;
  cout << "factorielle de " << nombre << " = " << factorielle(nombre) << endl;
  nombre = 10;
  cout << "fibonnaci de " << nombre << " = " << fibonnaci(nombre) << endl;
}
