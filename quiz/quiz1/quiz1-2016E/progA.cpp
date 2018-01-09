/* INF3105 / 2016E / Quiz 1 */
#include <iostream>
#include "tableau.h"
using namespace std;

// PROGRAMME A
bool fa(const Tableau<int>& tab) {
  int compteur = 0;
  for (int i = 0; i < tab.taille(); i++) {
    for (int j = i + 1; j < tab.taille(); j++) {
      for (int k = 0; k < tab.taille(); k++) {
        if (tab[i] + tab[j] == tab[k]) {
          ++compteur;
          cout << compteur << " fois" << endl;
          return true;
        }
        ++compteur;
      }
    }
  }
  cout << compteur << " fois" << endl;
  return false;
}

int main(int argc, const char** argv) {
  cout << "Entrez des nombres " << "(zéro pour arrêter):";
  Tableau<int> tab;
  while (cin) {
    int nombre = 0;
    cin >> nombre;
    if (nombre == 0) break;
    tab.ajouter(nombre);
  }

  if (fa(tab))
    cout << "Eureka!" << endl;
  return 0;
}
