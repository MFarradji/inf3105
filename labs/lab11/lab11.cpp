/*  INF3105 - Structures de données et algorithmes
     Lab 11 -- Graphes / Représentation et algorithmes de base
     http://info.uqam.ca/~beaudry/INF3105/lab11/                  */

#include <string>
#include <iostream>
#include "graphe.h"

using namespace std;

void premierGraphe();
void deuxiemeGraphe();
void troisiemeGraphe();

int main() {
  premierGraphe();
  deuxiemeGraphe();
  troisiemeGraphe();
  return 0;
}

void premierGraphe() {
  cout << "Création du graphe #1 non orienté de Figure 58(a) à la page 115" << endl;
  Graphe<string> graphe1;
  graphe1.ajouterSommet("a");
  graphe1.ajouterSommet("b");
  graphe1.ajouterSommet("c");
  graphe1.ajouterSommet("d");
  graphe1.ajouterSommet("e");
  graphe1.ajouterSommet("f");
  graphe1.ajouterSommet("g");
  graphe1.ajouterSommet("h");
  graphe1.ajouterAreteNonOrientee("a", "b");
  graphe1.ajouterAreteNonOrientee("a", "c");
  graphe1.ajouterAreteNonOrientee("a", "e");
  graphe1.ajouterAreteNonOrientee("b", "c");
  graphe1.ajouterAreteNonOrientee("b", "f");
  graphe1.ajouterAreteNonOrientee("c", "d");
  graphe1.ajouterAreteNonOrientee("d", "e");
  graphe1.ajouterAreteNonOrientee("d", "f");
  graphe1.ajouterAreteNonOrientee("d", "h");
  graphe1.ajouterAreteNonOrientee("e", "g");
  graphe1.ajouterAreteNonOrientee("f", "h");
  graphe1.ajouterAreteNonOrientee("g", "h");

  cout << "Recherche profondeur : a" << endl;
  graphe1.parcoursRechercheProfondeur("a");
  cout << "Recherche profondeur : c" << endl;
  graphe1.parcoursRechercheProfondeur("c");

  cout << "Recherche largeur : a" << endl;
  graphe1.parcoursRechercheLargueur("a");
  cout << "Recherche largeur : c" << endl;
  graphe1.parcoursRechercheLargueur("c");

  cout << "Composantes connexes :" << endl;
  graphe1.extraireCompostantesConnexes();
}

void deuxiemeGraphe() {
  // Graphe de la Figure 58(a) modifié.
  // Conseil : dessinez-le sur papier pour le visualiser.
  cout << "Création du graphe #2 non orienté" << endl;
  Graphe<string> graphe2;
  graphe2.ajouterSommet("a");
  graphe2.ajouterSommet("b");
  graphe2.ajouterSommet("c");
  graphe2.ajouterSommet("d");
  graphe2.ajouterSommet("e");
  graphe2.ajouterSommet("f");
  graphe2.ajouterSommet("g");
  graphe2.ajouterSommet("h");
  graphe2.ajouterSommet("x"); // ajout
  graphe2.ajouterSommet("y"); // ajout
  graphe2.ajouterSommet("z"); // ajout
  graphe2.ajouterAreteNonOrientee("a", "b");
  graphe2.ajouterAreteNonOrientee("a", "c");
  //graphe2.ajouterAreteNonOrientee("a", "e");
  graphe2.ajouterAreteNonOrientee("b", "c");
  //graphe2.ajouterAreteNonOrientee("b", "f");
  //graphe2.ajouterAreteNonOrientee("c", "d");
  graphe2.ajouterAreteNonOrientee("d", "e");
  graphe2.ajouterAreteNonOrientee("d", "f");
  graphe2.ajouterAreteNonOrientee("d", "h");
  graphe2.ajouterAreteNonOrientee("e", "g");
  graphe2.ajouterAreteNonOrientee("f", "h");
  graphe2.ajouterAreteNonOrientee("g", "h");
  graphe2.ajouterAreteNonOrientee("x", "y");

  cout << "Recherche profondeur : a" << endl;
  graphe2.parcoursRechercheProfondeur("a");
  cout << "Recherche profondeur : c" << endl;
  graphe2.parcoursRechercheProfondeur("c");

  cout << "Recherche largeur : a" << endl;
  graphe2.parcoursRechercheLargueur("a");
  cout << "Recherche largeur : c" << endl;
  graphe2.parcoursRechercheLargueur("c");

  cout << "Composantes connexes :" << endl;
  graphe2.extraireCompostantesConnexes();
}

void troisiemeGraphe() {
  cout << "Création du graphe #3 orienté Figure 58(b) de la page 115" << endl;
  Graphe<string> graphe3;
  graphe3.ajouterSommet("a");
  graphe3.ajouterSommet("b");
  graphe3.ajouterSommet("c");
  graphe3.ajouterSommet("d");
  graphe3.ajouterSommet("e");
  graphe3.ajouterSommet("f");
  graphe3.ajouterSommet("g");
  graphe3.ajouterSommet("h");
  graphe3.ajouterAreteOrientee("a", "b");
  graphe3.ajouterAreteOrientee("a", "e");
  graphe3.ajouterAreteOrientee("b", "a");
  graphe3.ajouterAreteOrientee("b", "c");
  graphe3.ajouterAreteOrientee("b", "f");
  graphe3.ajouterAreteOrientee("c", "a");
  graphe3.ajouterAreteOrientee("c", "b");
  graphe3.ajouterAreteOrientee("d", "c");
  graphe3.ajouterAreteOrientee("d", "e");
  graphe3.ajouterAreteOrientee("d", "h");
  graphe3.ajouterAreteOrientee("e", "d");
  graphe3.ajouterAreteOrientee("e", "g");
  graphe3.ajouterAreteOrientee("f", "d");
  graphe3.ajouterAreteOrientee("g", "e");
  graphe3.ajouterAreteOrientee("g", "h");
  graphe3.ajouterAreteOrientee("h", "f");

  cout << "Recherche profondeur : a" << endl;
  graphe3.parcoursRechercheProfondeur("a");
  cout << "Recherche profondeur : c" << endl;
  graphe3.parcoursRechercheProfondeur("c");

  cout << "Recherche largeur : a" << endl;
  graphe3.parcoursRechercheLargueur("a");
  cout << "Recherche largeur : c" << endl;
  graphe3.parcoursRechercheLargueur("c");

  cout << "Composantes connexes :" << endl;
  graphe3.extraireCompostantesConnexes();
}
