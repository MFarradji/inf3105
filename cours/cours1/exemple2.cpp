#include <iostream>

using namespace std;

int somme(int);

// ex. somme
int main() {
  int n = 4;
  cout << "Somme pour n = " << n << " : " << somme(n) << endl;
  return 0;
}

// fonction
int somme(int n) {
  int resultat = 0;
  // boucle
  for(int i = 0; i <= n; ++i) {
    resultat += i;
  }
  return resultat;
}
