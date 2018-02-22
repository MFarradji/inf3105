#if !defined(LISTE_HPP)
#define LISTE_HPP

#include <iostream>

using namespace std;

template <class T>
class Liste {
  public:
    Liste() {
      premiere = nullptr;
    }
    //~Liste();

    Liste<T> inverse() const;
    void ajouter(int debut, int fin, int increment);
    void afficher() const;
    
    private:
      class Cellule {
        public:
          Cellule* precedente;
          Cellule* suivante;
          T element;

          Cellule(const T& e, Cellule *p, Cellule* s) : precedente(p), suivante(s) {
            element = e;
          }
      };
      Cellule* premiere;
};

template <class T>
Liste<T> Liste<T>::inverse() const {
  Liste liste;
  Cellule* courante1 = premiere;
  Cellule* cellule = cellule = new Cellule(courante1->element, nullptr, nullptr);
  Cellule* suivante2 = nullptr;
  while (courante1->suivante != nullptr) {
    courante1 = courante1->suivante;
    suivante2 = cellule;
    cellule = new Cellule(courante1->element, nullptr, suivante2);
    suivante2->precedente = cellule;
  }
  liste.premiere = cellule;
  return liste;
}

template <class T>
void Liste<T>::ajouter(int debut, int fin, int increment) {
  premiere = new Cellule(debut, nullptr, nullptr);
  Cellule* precedente = premiere;
  for (int i = debut + 1; i < fin; i += increment) {
    Cellule* courante = new Cellule(i, precedente, nullptr);
    precedente->suivante = courante;
    precedente = courante;
  }
}

template <class T>
void Liste<T>::afficher() const {
  Cellule* courante = premiere;
  while (courante != nullptr) {
    cout << courante->element << " ";
    courante = courante->suivante;
  }
  cout << endl;
}

#endif
