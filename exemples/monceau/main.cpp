#include <iostream>
#include "monceau.hpp"

using namespace std;

int main() {
  int tab[] = {7, 8, 1, 5, 9, 10, 5};
  int taille = sizeof(tab) / sizeof(*tab);
  Monceau monceau;
  cout << "insertion" << endl;
  for (int i = 0; i < taille; i++) {
    monceau.inserer(tab[i]);
    monceau.afficher();
  }
  cout << "suppression" << endl;
  for (int i = 0; i < taille; i++) {
    monceau.supprimerMin();
    monceau.afficher();
  }
}
