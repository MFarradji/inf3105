/*
  INF3105 - Structures de données et algorithmes

  Squellette pour le Lab6 (Tâche 4 - Question 3 de l'examen pratique de mi-session 2012H)
  
  Pour compilter : g++ -o lab6 lab6-tache4.cpp
*/

#include <iostream>
#include <fstream>

#include "arbreavl.h"

using namespace std;

class Paire {
  public:
    double date;
    double temperature;

    Paire(double d, double t);

    bool operator < (const Paire& autre) const;
    bool operator == (const Paire& autre) const;
};

Paire::Paire(double d, double t) : date(d), temperature(t) {}

bool Paire::operator < (const Paire& autre) const {
  if (this == &autre) {
    return false;
  }
  if (date < autre.date) {
    return true;
  }
  return false;
}

bool Paire::operator == (const Paire& autre) const {
  if (this == &autre) {
    return false;
  }
  return date == autre.date;
}

class Historique {
  private:
    ArbreAVL<Paire> arbre;

  public:
    void ajouter(double date, double temperature);
    double estimerTemperature(double date) const;
    double calculerMoyenne(double debut, double fin) const;
};

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Exemple d'usage : ./lab6 fichier.txt < entree.txt" << endl;
    return 1;
  }

  ifstream in(argv[1]);
  Historique h;
  while (in) {
    double d, t;
    in >> d >> t;
    if (in) {
      h.ajouter(d,t);
    }
  }

  while (cin) {
    double d1, d2;
    cin >> d1 >> d2;
    if (cin) {
      double t1 = h.estimerTemperature(d1);
      double t2 = h.estimerTemperature(d2);
      double moy = h.calculerMoyenne(d1, d2);
      cout << "t1=" << t1 << '\t' << "t2=" << t2 << '\t' << moy << endl;
    }
  }
  return 0;
}

void Historique::ajouter(double date, double temperature) {
  Paire paire(date, temperature);
  arbre.inserer(paire);
}

double Historique::estimerTemperature(double date) const {
  Paire p1(date, 0);
  const Paire* p2 = arbre.recherche(p1);
  if (p2 != nullptr) {
    return p2->temperature; 
  }
  Paire prec = arbre[arbre.rechercherEgalOuPrecedent(p1)];
  Paire suiv = arbre[arbre.rechercherEgalOuSuivant(p1)];
  // interpolation linéaire
  // y = y0 * (x1 - x) + y1 * (x - x0)) / (x1 - x0);
  return (prec.temperature * (suiv.date - date) + suiv.temperature * (date - prec.date)) / (suiv.date - prec.date);
}

double Historique::calculerMoyenne(double debut, double fin) const {
  Paire p1(debut, 0);
  Paire p2(fin, 0);
  ArbreAVL<Paire>::Iterateur it1 = arbre.rechercher(p1);
  ArbreAVL<Paire>::Iterateur it2 = arbre.rechercher(p2);

  double t1 = it1 ? (*it1).temperature : estimerTemperature(debut);
  double t2 = it2 ? (*it2).temperature : estimerTemperature(fin);

  double total = t1 + t2;
  int n = 2;
  if (it1 && it2) {
    it1++;
    while (it1 != it2) {
      total += (*it1).temperature;
      n++;
      it1++;
    }
  }

  return total / n;
}
