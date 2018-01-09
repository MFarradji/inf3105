#if !define(_PILE_HPP)
#define _PILE_HPP

#include "Maillon.hpp"

template <typename T>
class Pile<T> {
  protected:
    Maillon<T>* _sommet;
    int _taille;
  public:
    Pile(void);
    Pile(const Pile<T>&); // copie légère pour passage de paramètre dans une fonction
    // (optionnel) constructeur par copie forte
    virtual ~Pile(void);
    T* sommet(void) throw(PileVide) const;
    int taille(void) const;
    bool estVide(void) const;
    void empiler(T* a_element); // new
    void depiler(void) throw(PileVide); // delete
};

#endif
