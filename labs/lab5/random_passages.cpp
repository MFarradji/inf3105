/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique

  Lab4
  Programme pour générer des tests aléatoirement.
*/

#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, const char** argv) {
  int nbpassages = 100000;
  int nbcartes = 10000;
  double delaimoyen = 1.0;

  if (argc > 1) nbpassages = atoi(argv[1]);
  if (argc > 2) nbcartes = atoi(argv[2]);
  if (argc > 3) delaimoyen = atof(argv[3]);

  random_device rd;
  mt19937 gen(rd());
  exponential_distribution<> dist2(1 / delaimoyen);
  // Nécessite un compilateur supportant la norme C++ 2011 (fonctionne sur rayon1 et rayon2).
  uniform_int_distribution<> dist10000(0, nbcartes - 1);

  double time = 0;
  for (int i = 0; i < nbpassages; i++) {
    double dt = dist2(gen);
    int carte = dist10000(gen);

    time += dt;

    cout << (int) time << " " << (10000 + carte) << endl;
  }
}
