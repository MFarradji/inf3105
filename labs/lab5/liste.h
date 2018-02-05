/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique

  Liste simplement chaînée.
*/

#if !defined(__LISTE_H__)
#define __LISTE_H__

#include <assert.h>

template <class T>
class Liste {
  public:
    class Iterateur;

    Liste();
    ~Liste();

    bool estVide() const;
    void vider();

    bool operator == (const Liste&) const;

    const Liste& operator = (const Liste&);

    T& operator[] (const Iterateur&);
    const T& operator[] (const Iterateur&) const;

    // Les fonctions insérer retournent un Itérateur sur la position de l'objet inséré.
    // La fonction enlever retourne un Iterateur sur la position suivante de l'objet enlevé.
    Iterateur inserer(const T&, const Iterateur&);
    Iterateur enlever(const Iterateur&);

    Iterateur inserer_debut(const T&);
    Iterateur inserer_fin(const T&);
    void      enlever_debut();

    Iterateur debut() const; // Iterateur sur le début.
    Iterateur fin() const;   // Iterateur sur la fin. La fin est la position suivante du dernier élément.

    // Retourne un itérateur sur le premier élément cherché. S'il n'existe pas, retourne fin().
    Iterateur trouver(const T&) const;

  private:
    class Cellule {
      public:
        Cellule(const T& c, Cellule* s = nullptr) : suivante(s) {
          contenu = c;
        }
        T contenu;
        Cellule* suivante;
    };

  public:
    class Iterateur {
      public:
        Iterateur(const Iterateur&);
        Iterateur(const Liste&);

        // retourne vrai si l'itérateur n'est pas rendu à la fin. Permet de faire while(iter)
        operator bool() const;
        bool operator ! () const; // retourne faux si l'itérateur n'est pas rendu à la fin
        bool operator == (const Iterateur&) const; // compare deux itérateur (deux "positions")
        bool operator != (const Iterateur&) const; // !compare deux itérateur (deux "positions")

        Iterateur& operator ++ (); // pré-incrément (passe au suivant)
        Iterateur operator ++ (int);  // post-incrément (passe au suivant)

        const T& operator * () const; // déréférencement

        Iterateur& operator = (const Iterateur&); // affecte l'itérateur à la valeur d'un autre

     private:
        Cellule* precedente; // pointeur sur la Cellule précédente de la position courante
        // référence sur la Liste associée à l'itérateur courant (pour des fins de robustesse).
        const Liste& liste;
        friend class Liste;
    };

  private:
    Liste(const Liste&);

    Cellule* derniere;
};

// Implémentation des constructeurs, destructeurs et fonctions
template <class T>
Liste<T>::Liste() {
  derniere = nullptr;
}

template <class T>
Liste<T>::~Liste() {
  vider();
}

template <class T>
bool Liste<T>::estVide() const {
  return derniere == nullptr;
}

template <class T>
void Liste<T>::vider() {
  Cellule* c = derniere;
  while (c != nullptr) {
    Cellule* temp = c->suivante;
    delete c;
    c = temp;
    if (c == derniere)
      c = nullptr;
  }
  derniere = nullptr;
}

template <class T>
const Liste<T>& Liste<T>::operator = (const Liste<T>& autre) {
  if (this == &autre) return *this;
  vider();
  for (Iterateur ia = autre.debut(); ia; ia++)
    inserer_fin(*ia);
  return *this;
}

template <class T>
T& Liste<T>::operator [] (const Iterateur& i) {
  assert(&i.liste == this);
  assert(i.precedente != nullptr);
  return i.precedente->suivante->contenu;
}

template <class T>
const T& Liste<T>::operator [] (const Iterateur& i) const {
  assert(&i.liste == this);
  assert(i.precedente != nullptr);
  return i.precedente->suivante->contenu;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer(const T& e, const Iterateur& i) {
  assert(this == &i.liste);
  Iterateur position(i);
  Cellule* c = i.precedente;
  if (derniere == nullptr) {
    derniere = new Cellule(e);
    c = derniere->suivante = derniere;
  } else if (c == nullptr) {
    c = derniere;
    derniere->suivante = new Cellule(e, derniere->suivante);
    derniere = derniere->suivante;
  } else {
    c->suivante = new Cellule(e, c->suivante);
  }
  position.precedente = c;
  return position;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer_debut(const T& e) {
  return inserer(e, debut());
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer_fin(const T& e) {
  return inserer(e, fin());
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::enlever(const Iterateur& i) {
  assert(&i.liste == this);
  Iterateur position(i);
  Cellule* c = i.precedente;
  assert(c != nullptr && derniere != nullptr);
  Cellule* temp = c->suivante;
  c->suivante = temp->suivante;
  delete temp;
  Cellule* retour = temp == derniere ? nullptr : c;
  // si on efface la dernière cellule, il faut mettre à jour derniere
  if (derniere == temp)
    derniere = c;
  if (temp == c)
    derniere = c = nullptr;
  position.precedente = retour;
  return position;
}

template <class T>
void Liste<T>::enlever_debut() {
  enlever(debut());
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::debut() const {
  return Iterateur(*this);
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::fin() const {
  Iterateur iter(*this);
  iter.precedente = nullptr;
  return iter;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::trouver(const T& e) const {
  Iterateur iter(*this);
  while(iter && !(*iter == e))
    iter++;
  return iter;
}

template <class T>
bool Liste<T>::operator == (const Liste& autre) const {
  if (this == &autre) return true;
  Iterateur i1 = debut();
  Iterateur i2 = autre.debut();
  while (i1 && i2) {
    if (*i1 != *i2)
      return false;
    ++i1; ++i2;
  }
  if(i1 && !i2) return false;
  if(!i1 && i2) return false;
  return true;
}

// Iterateur ****************************************************
template <class T>
Liste<T>::Iterateur::Iterateur(const Iterateur& i) : liste(i.liste) {
  precedente = i.precedente;
}

template <class T>
Liste<T>::Iterateur::Iterateur(const Liste<T>& l) : liste(l) {
  precedente = l.derniere;
}

template <class T>
bool Liste<T>::Iterateur::operator !() const {
  return precedente == nullptr;
}

template <class T>
Liste<T>::Iterateur::operator bool() const {
  return precedente != nullptr;
}

// ne tient pas commpte des éléments dupliqués
template <class T>
bool Liste<T>::Iterateur::operator == (const Iterateur& autre) const {
  return precedente == autre.precedente && &liste == &(autre.liste);
}

template <class T>
bool Liste<T>::Iterateur::operator != (const Iterateur& autre) const {
  return precedente != autre.precedente || &liste != &(autre.liste);
}

// operator ++ () est le pré-incrément
template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator ++ () {
  precedente = precedente->suivante;
  if (precedente == liste.derniere)
    precedente = nullptr;
  return *this;
}

// operator ++ (int) est le post-incrément
template <class T>
typename Liste<T>::Iterateur Liste<T>::Iterateur::operator ++ (int) {
  Iterateur temp(*this);
  precedente = precedente->suivante;
  if (precedente == liste.derniere)
    precedente = nullptr;
  return temp;
}

template <class T>
const T& Liste<T>::Iterateur::operator *() const {
  return liste[*this];
}

template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator = (const Iterateur& autre) {
  assert(&liste == &(autre.liste));
  precedente = autre.precedente;
  return *this;
}

#endif
