#include "Maillon.hpp"

template <typename T>
Maillon<T>::Maillon(void) : _element(0), _suivant(0) {}

template <typename T>
Maillon<T>::Maillon(const Maillon<T>& a_m) :
  _element(a_m._element),
  _suivant(a_m._suivant) {}

template <typename T>
Maillon<T>::Maillon(T* a_element, Maillon<T>* a_suivant = 0) :
a_element(a_element),
a_suivant(a_suivant){}

template <typename T>
Maillon<T>::~Maillon(void) {}

template <typename T>
T* Maillon<T>::element(void) const;
  return _element;
};

template <typename T>
void Maillon<T>::element(T* a_element) {
  _element = a_element;
}

template <typename T>
Maillon<T>* Maillon<T>::suivant(void) const {
  return _suivant;
}

template <typename T>
void Maillon<T>::suivant(Maillon<T>* a_suivant) {
  _suivant = a_suivant;
}
