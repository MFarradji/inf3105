/*  INF3105 - Structures de données et algorithmes
     Lab 11 -- Graphes / Représentation et algorithmes de base
     http://info.uqam.ca/~beaudry/INF3105/lab11/                  */

#if !defined(GRAPHE_H)
#define GRAPHE_H

#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

// Le type S est le type utilisé pour identifier les sommets
template <class S>
class Graphe {
  public:
    // Interface public pour créer le graphe.
    void ajouterSommet(const S& s);
    void ajouterAreteOrientee(const S& s1, const S& s2);
    void ajouterAreteNonOrientee(const S& s1, const S& s2);

    // Interface public pour les requêtes de base.
    // Amélioration possible : retourner le résultat au lieu de faire l'affichage à l'interne.
    void parcoursRechercheProfondeur(const S& s) const;
    void parcoursRechercheLargueur(const S& s) const;
    void parcoursRechercheLargueur(const S& s, set<S>& visites) const;
    void extraireCompostantesConnexes() const;

  private:
    struct Sommet {
      set<S> voisins; // ensemble des sommets accessibles via les arêtes sortantes du sommet.
                      // Cela est légèrement différent de la page 120 des notes de cours.
                      // C'est voulu, car ici les arêtes ne sont pas étiquetées par un poids (ex: distance).
                      // Pour attacher une étiquette, il suffirait de modifier pour : map<S, A> sortants;
    };
    map<S, Sommet> sommets; // identification --> sommet
};

template <class S>
void Graphe<S>::ajouterSommet(const S& s) {
  sommets[s] = Sommet();
}

template <class S>
void Graphe<S>::ajouterAreteNonOrientee(const S& s1, const S& s2) {
  // Doit ajouter les 2 arêtes orientées : s1->s2 et s2->s1;
  sommets[s1].voisins.insert(s2);
  sommets[s2].voisins .insert(s1);
}

template <class S>
void Graphe<S>::ajouterAreteOrientee(const S& s1, const S& s2) {
  // Doit uniquement ajouter s1->s2.
  sommets[s1].voisins.insert(s2);
}

template <class S>
void Graphe<S>::parcoursRechercheProfondeur(const S& s) const {
  set<S> visites;
  stack<S> pile;
  visites.insert(s);
  pile.push(s);

  while (!pile.empty()) {
    const S& suivant = pile.top();
    cout << suivant << ' ';
    pile.pop();
    for (auto voisin : sommets.at(suivant).voisins) {
      if (visites.count(voisin) == 0) {
        visites.insert(voisin);
        pile.push(voisin);
      }
    }
  }
  cout << endl;
}

template <class S>
void Graphe<S>::parcoursRechercheLargueur(const S& s) const {
  set<S> visites;
  parcoursRechercheLargueur(s, visites);
  cout << endl;
}

template <class S>
void Graphe<S>::parcoursRechercheLargueur(const S& s, set<S>& visites) const {
  queue<S> file;
  visites.insert(s);
  file.push(s);

  while (!file.empty()) {
    const S& suivant = file.front();
    cout << suivant << ' ';
    file.pop();
    const set<S>& voisins = sommets.at(suivant).voisins;
    for (typename set<S>::const_iterator it = voisins.begin(); it != voisins.end(); ++it) {
      if (visites.count(*it) == 0) {
        visites.insert(*it);
        file.push(*it);
      }
    }
  }
}

template <class S>
void Graphe<S>::extraireCompostantesConnexes() const {
  // Ne faites que l'extraction simple en premier (plus simple que l'extraction de composantes *fortement* connexes).
  cout << "{ " ;
  set<S> visites;
  for (typename map<S, Sommet>::const_iterator it = sommets.begin(); it != sommets.end(); ++it) {
    if (visites.count(it->first) == 0) {
      cout << "{ " ;
      parcoursRechercheLargueur(it->first, visites);
      cout << "} ";
    }
  }
  cout << "}" << endl;
}

#endif
