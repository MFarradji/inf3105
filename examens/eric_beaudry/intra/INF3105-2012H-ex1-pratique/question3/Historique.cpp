#include "Historique.hpp"

#include <iostream>

using namespace std;

void Historique::ajouter(double date, double temperature) {
  couples.push_back(Couple(date, temperature));
}

double Historique::estimeTemperature(double date) const {
  double temperature = 0;
  int taille = couples.size();
  int borneInf = 0;
  int borneSup = taille - 1;
  int indice = -1;

  // recherche binaire
  while (borneInf <= borneSup && indice == -1) {
    int milieu = (borneInf + borneSup) / 2;
    if (couples[milieu].date == date)
      indice = milieu;
    else if (couples[milieu].date > date)
      borneSup = milieu - 1;
    else
      borneInf = milieu + 1;
  }

  if (indice != -1) {
    temperature = couples[indice].temperature;
  } else {
    // Trouver l'équation de la droite entre borneInf et borneSup
    // y = mx + k
    // x = date, y = temperature
    // m = pente de la droite = (y2 - y1) / (x2 - x1)
    double m = (couples[borneSup].temperature - couples[borneInf].temperature) /
               (couples[borneSup].date - couples[borneInf].date);
    // k = ordonnée à l'origine = y - mx
    double k = couples[borneInf].temperature  - m * couples[borneInf].date;
    temperature = m * date + k;
  }

  return temperature;
}

double Historique::calculeMoyenne(double dateDebut, double dateFin) const {
  double somme = 0;
  int taille = couples.size();
  int borneDebut = 0;
  int borneInf = 0;
  int borneSup = taille - 1; // borneFin = borneSup

  // recherche binaire de dateDebut
  while (couples[borneInf].date < dateDebut) {
    int milieu = (borneInf + borneSup) / 2;
    if (couples[milieu].date == dateDebut) {
      borneInf = milieu;
    } else if (couples[milieu].date > dateDebut) {
      borneSup = milieu - 1;
    } else {
      borneInf = milieu + 1;
    }
   }

  borneDebut = borneInf;
  borneSup = taille - 1;

  // recherche binaire de dateFin
  while (couples[borneSup].date > dateFin) {
    int milieu = (borneInf + borneSup) / 2;
    if (couples[milieu].date == dateFin) {
      borneSup = milieu;
    } else if (couples[milieu].date > dateFin) {
      borneSup = milieu - 1;
    } else {
      borneInf = milieu + 1;
    }
  }

  // calculer la moyenne entre borneDebut et borneSup
  for (int i = borneDebut; i <= borneSup; i++) {
    somme += couples[i].temperature;
  }

  double tailleEchantillon = borneSup - borneDebut + 1;
  return somme / tailleEchantillon;
}
