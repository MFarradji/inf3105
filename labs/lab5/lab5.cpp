/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  Lab5
*/

#include <iostream>
#include "liste.h"

using namespace std;

class PassageCarte {
  public:
    int time;
    int numeroCarte;

  friend istream& operator >> (istream&, PassageCarte&);
  friend ostream& operator << (ostream&, const PassageCarte&);
};

istream& operator >> (istream& is, PassageCarte& pc) {
  is >> pc.time >> pc.numeroCarte;
  return is;
}

ostream& operator << (ostream& os, const PassageCarte& pc) {
  os << pc.time << "	" << pc.numeroCarte;
  return os;
}

int main(int argc, const char** argv) {
  Liste<PassageCarte> liste_passages;

  while (cin) {
    PassageCarte p1;
    cin >> p1;
    if (!cin) {
      break;
    }

    // Enlever les passages vieux de plus de 10 minutes
    for (Liste<PassageCarte>::Iterateur iter = liste_passages.debut(); iter; iter = liste_passages.debut()) {
      PassageCarte debut = liste_passages[iter];
      if (debut.time + 600 < p1.time) {
        liste_passages.enlever_debut();
      } else {
        break;
      }
    }

    if (liste_passages.estVide()) {
      liste_passages.inserer_fin(p1);
    } else {
      // Detecter les passages invalides
      bool valide = true;
      for (Liste<PassageCarte>::Iterateur iter = liste_passages.debut(); valide && iter; ++iter) {
        PassageCarte p2 = liste_passages[iter];
        if (p2.numeroCarte == p1.numeroCarte) {
          cout << "Passage invalide : " << p1 << "!" << endl;
          valide = false;
        }
      }

      if (valide) {
        liste_passages.inserer_fin(p1);
      }
    }
  }
}
