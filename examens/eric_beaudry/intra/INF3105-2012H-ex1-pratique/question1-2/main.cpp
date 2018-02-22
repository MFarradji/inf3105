#include "liste.hpp"

int main() {
  Liste<int> liste;
  liste.ajouter(1, 10, 1);
  liste.afficher();
  Liste<int> inverse = liste.inverse();
  inverse.afficher(); 
}
