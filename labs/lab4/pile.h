/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
*/

#if !defined(PILE_H)
#define PILE_H

#include "assert.h"

using namespace std;

template <class T>
class Pile {
  public:
    Pile();
    Pile(const Pile&);
    ~Pile();

    void empiler(const T&);

    void depiler(T& out); // depiler et copier le sommet dans out.
    T depiler();

    bool vide() const;
    void vider();

    void afficher();

    Pile<T>& operator = (const Pile<T>& autre);

  private:
    class Cellule {
      public:
        Cellule(const T& e, Cellule* c);
        Cellule(const T& e);
        T contenu;
        Cellule* suivante = nullptr;
    };

    Cellule* sommet;

    void copier(const Pile<T>& autre);
};

/*
  Puisque Pile<T> est une classe générique, toutes ses définitions doivent être
  inclues après les déclarations. On peut quand même séparer les déclarations et
  les définitions en deux fichiers (pile.h et pile.hcc), à condition d'inclure le
  deuxième (pile.hcc) à la fin du premier (pile.h). Ainsi, un fichier source
  (.cc, .cpp, c++) qui inclut pile.h inclura indirectement aussi pile.hcc.
*/

template <class T>
Pile<T>::Pile() {
  sommet = nullptr;
}

template <class T>
Pile<T>::Pile(const Pile& autre) {
  sommet = nullptr;
  copier(autre);
}

// destructeur
template <class T>
Pile<T>::~Pile() {
  vider();
}

template <class T>
bool Pile<T>::vide() const {
  return sommet == nullptr;
}

template <class T>
void Pile<T>::vider() {
  while(!vide())
    depiler();
}

template <class T>
Pile<T>::Cellule::Cellule(const T& e, Cellule* c) : contenu(e), suivante(c) {}

template <class T>
Pile<T>::Cellule::Cellule(const T& e) : contenu(e) {}

template <class T>
void Pile<T>::empiler(const T& e) {
  sommet = new Cellule(e, sommet);
  assert(sommet);
}

template <class T>
T Pile<T>::depiler() {
  assert(sommet != nullptr);
  Cellule c(*sommet);
  delete sommet;
  sommet = c.suivante;
  return c.contenu;
}

template <class T>
void Pile<T>::depiler(T& e) {
  assert(sommet != nullptr);
  e = sommet->contenu;
  Cellule* c = sommet;
  sommet = sommet->suivante;
  delete c;
}

template <class T>
void Pile<T>::afficher() {
  Cellule *c = sommet;
  while (c != nullptr) {
    cout << c->contenu << " ";
    c = c->suivante;
  }
  cout << endl;
}

template <class T>
Pile<T>& Pile<T>::operator = (const Pile<T>& autre) {
  if (this == &autre)
    return *this;
  vider();
  copier(autre);
  return *this;
}

template <class T>
void Pile<T>::copier(const Pile<T>& autre) {
  if (autre.sommet != nullptr) {
    sommet = new Cellule(autre.sommet->contenu);
    Cellule *cp = autre.sommet;
    Cellule *c = sommet;
    while (cp->suivante != nullptr) {
      c->suivante = new Cellule(cp->suivante->contenu);
      c = c->suivante;
      cp = cp->suivante;
    }
    c->suivante = nullptr;
  }
}

#endif

