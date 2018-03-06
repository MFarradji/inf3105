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
  ArbreAVL<Paire>::Iterateur iter = arbre.rechercherEgalOuPrecedent(p1);
  if (!iter) {
    return (*arbre.debut()).temperature;
  }
  const Paire& prec = *iter;
  Paire suiv = arbre[arbre.rechercherEgalOuSuivant(p1)];
  // interpolation linéaire
  // y = y0 * (x1 - x) + y1 * (x - x0)) / (x1 - x0);
  return (prec.temperature * (suiv.date - date) + suiv.temperature * (date - prec.date)) / (suiv.date - prec.date);
}

double Historique::calculerMoyenne(double debut, double fin) const {
  ArbreAVL<Paire>::Iterateur iter = arbre.rechercherEgalOuPrecedent(Paire(debut, 0));
  if (!iter) iter = arbre.debut();
  // 1 = debut interval, 2 = fin interval, d = date, t = temperature
  double d1, d2, t1, t2;
  double somme = 0; // somme de temperature * duree
  while (iter && (*iter).date < fin) {
    if ((*iter).date < debut) {
      d1 = debut;
      t1 = estimerTemperature(debut);
    } else {
      d1 = (*iter).date;
      t1 = (*iter).temperature;
    }
    ++iter;
    if (!iter) break;
    if ((*iter).date > fin) {
      d2 = fin;
      t2 = estimerTemperature(fin);
    } else {
      d2 = (*iter).date;
      t2 = (*iter).temperature;
    }
    somme += ((t2 + t1) / 2.0) * (d2 - d1); // moyenne pondérée
  }
  return somme / (fin - debut);
}
