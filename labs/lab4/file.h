/*
  INF3105 - Structures de donnees et algorithmes
  UQAM / Departement d'informatique
*/

#pragma once

#include <assert.h>

template <class T>
class File {
  public:
    File();
    ~File();

    void  enfiler(const T&);
    T     defiler();

    bool  vide() const;
    void vider();
    const T& tete() const;

    File<T>& operator = (const File<T>& autre);

  private:
    class Cellule {
      public:
        Cellule(const T& e, Cellule* c = nullptr);
        T element;
        Cellule* suivante;
    };

    Cellule *queue; // dernier de la file
};

template <class T>
File<T>::File() {
  queue = nullptr;
}

template <class T>
File<T>::~File() {
  vider();
}

template <class T>
bool File<T>::vide() const {
  return queue == nullptr;
}

template <class T>
void File<T>::vider() {
  while (!vide())
    defiler();
}

template <class T>
const T& File<T>::tete() const {
  assert(queue != nullptr);
  return queue->suivante->element;
}

template <class T>
File<T>::Cellule::Cellule(const T& e, Cellule* c) : element(e), suivante(c) {
}

template <class T>
void File<T>::enfiler(const T& e) {
  if (queue == nullptr) {
    queue = new Cellule(e);
    queue->suivante = queue;
  } else {
    queue->suivante = new Cellule(e, queue->suivante);
    queue = queue->suivante;
  }
}

template <class T>
T File<T>::defiler() {
  Cellule* c = queue->suivante; // premier de la file
  T e = c->element;
  if (queue == c)
    queue = nullptr; // file vide
  else
    queue->suivante = c->suivante;
  delete c;
  return e;
}

template <class T>
File<T>& File<T>::operator = (const File<T>& autre) {
  if (this == &autre)
    return *this;
  vider();

  // copie
  if (autre.queue != nullptr) {
    queue = new Cellule(autre.queue->element);
    Cellule *cp = autre.queue;
    Cellule *c = queue;
    while (cp->suivante != autre.queue) {
      c->suivante = new Cellule(cp->suivante->element);
      c = c->suivante;
      cp = cp->suivante;
    }
    c->suivante = queue;
  }

  return *this;
}
