#include <iostream>
#include "monceau.hpp"

using namespace std;

Monceau::Monceau() {}

void Monceau::afficher() {
  for (unsigned i = 0; i < tab.size(); ++i)
    cout << tab[i] << ' ';
  cout << endl;
}

void Monceau::inserer(int valeur) {
  tab.push_back(valeur);
  int indice = tab.size() - 1;
  if (indice != 0) {
    bool monter = false;
    do {
      int parent = (indice - 1) / 2;
      monter = tab[indice] < tab[parent];
      if (monter) {
        echanger(indice, parent);
        indice = parent;
      }
    } while (monter);
  }
}

void Monceau::supprimerMin() {
  echanger(0, tab.size() - 1);
  tab.pop_back();
  unsigned indice = 0;
  bool descendre = false;
  do {
    unsigned suivant = 2 * indice + 1;
    descendre = suivant < tab.size();
    if (descendre) {
      if (suivant + 1 < tab.size() && tab[suivant + 1] < tab[suivant])
        ++suivant;
      descendre = tab[suivant] < tab[indice];
      if (descendre) {
        echanger(suivant, indice);
        indice = suivant;
      }
    }
  } while(descendre);
}

int Monceau::min() {
  return tab[0];
}

bool Monceau::estVide() const {
  return tab.empty();
}

void Monceau::echanger(int i, int j) {
  int temp = tab[i];
  tab[i] = tab[j];
  tab[j] = temp;
}
