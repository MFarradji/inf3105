#include "Liste.hpp"

template <class T>
Liste Liste<T>::inverse() const {
  Liste liste;
  if (premiere != nullptr) {
    Cellule derniere = new Cellule(premiere->element, liste.premiere, nullptr);
    liste.premiere = derniere;
    Cellule* courante = premiere->suivante;
    while (courante != nullptr) {
      liste.premiere = new Cellule(courante->element, nullptr, liste.premiere);
      liste.premiere.suivante.precedente = liste.premiere;
      courante = courante->suivante;
    }
    liste.premiere.precedente = derniere;
  }
  return liste;
}
