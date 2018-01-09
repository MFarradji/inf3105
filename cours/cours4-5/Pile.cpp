#include "Pile.hpp"
#include "Maillon.hpp"

template <typename T>
Pile<T>::Pile(void) : _sommet(nullptr), _taille(0) {}

template <typename T>
Pile<T>::Pile(const Pile<T>& a_pile) :
  _sommet(a_pile._sommet),
  _taille(a_pile._taille) {}

template <typename T>
Pile<T>::~Pile(void) {
  // à compléter (appel vider())
}

template <typename T>
T* Pile<T>::sommet(void) throw (PileVide) const;
  if (estVide())
    throw PileVide();
  return _sommet->_element();
};

template <typename T>
int Pile<T>::taille(void) const {
  return _taille;
}

template <typename T>
bool Pile<T>::estVide(void) const {
  return 0 == _taille;
}

template <typename T>
void Pile<T>::empiler(T* a_element) {
  _sommet = new Maillon<T>(a_element, _sommet);
  ++_taille;
}

template <typename T>
void Pile<T>::depiler(void) throw(PileVide) {
  if (estVide())
    throw PileVide();
  Maillon<T>* temp = _sommet;
  _sommet = _sommet->suivant();
  delete temp;
  --_taille;
}
