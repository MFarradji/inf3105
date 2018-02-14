#include <iostream>

using namespace std;

// récursion
// complexité temporelle = O(2^n) (exponentiel)
/*
unsigned fibonnaci(unsigned n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonnaci(n - 2) + fibonnaci(n - 1);
}
*/

// programmation dynamique
// complexité temporelle = O(n) (linéaire)
unsigned fibonnaci(unsigned n) {
  unsigned tab[n + 1];
  tab[0] = 0;
  tab[1] = 1;
  for (unsigned i = 2; i <= n; ++i) {
    tab[i] = tab[i - 2] + tab[i - 1];
  }
  return tab[n];
}

bool testFibonnaci() {
  cout << "Test Fibonnaci" << endl;
  unsigned nbErreurs = 0;
  unsigned taille = 10;
  unsigned solutions[taille] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

  for (unsigned i = 0; i < taille; ++i) {
    unsigned terme = fibonnaci(i);
    if (solutions[i] != terme) {
      cout << "  >> Erreur #" << i << endl;
      ++nbErreurs;
    }
  }
  if (nbErreurs == 0)
    cout << " ==> OK" << endl;
  return nbErreurs == 0;
}

int main(int argc, const char* argv[]) {
  testFibonnaci();
}
