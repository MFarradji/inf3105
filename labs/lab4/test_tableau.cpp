#include <iostream>
#include "tableau.h"
#include "pile.h"

using namespace std;

int main() {
  Tableau<Pile<int>> tab1;
  for (int i = 0; i < 10; i++) {
    Pile<int> pile;
    pile.empiler(-1);
    tab1.ajouter(pile);
    for (int j = 0; j < i; j++) {
      tab1[i].empiler(j);
    }
    cout << "pile #" << i << endl;
    tab1[i].afficher();
  }
  Tableau<Pile<int>> tab2;
  tab2 = tab1;
  for (int i = 0; i < 10; i++)
    tab1[i] = Pile<int>();
}
