#include <iostream>

using namespace std;

template <typename T>
void afficher(T* tab, int debut, int fin) {
  for (int i = debut; i <= fin; ++i)
    cout << tab[i] << " ";
  cout << endl;
}

template <typename T>
void fusion(T* tab, int debut, int milieu, int fin) {
  int taille = fin - debut + 1;
  T* temp = new T[taille];
  int i = debut;
  int j = milieu + 1;
  int k = 0;
  
  // sélectionner le minimum des deux cases i/j
  while (i <= milieu && j <= fin) {
    if (tab[i] < tab[j]) {
      temp[k] = tab[i];
      ++i;
    } else {
      temp[k] = tab[j];
      ++j;
    }
    ++k;
  }

  // placer les cases restantes
  while (i <= milieu) {
    temp[k] = tab[i];
    ++k;
    ++i;
  }

  while (j <= fin) {
    temp[k] = tab[j];
    ++j;
    ++k;
  }

  // copie dans le tableau original
  for (k = 0; k < taille; ++k)
    tab[debut + k] = temp[k];
  delete[] temp;
}

template <typename T>
void trifusion(T *tab, int debut, int fin) {
  if (fin - debut >= 1) {
    int milieu = (fin + debut) / 2;
    afficher(tab, debut, fin);
    trifusion(tab, debut, milieu);
    trifusion(tab, milieu + 1, fin);
    fusion(tab, debut, milieu, fin);
    afficher(tab, debut, fin);
  }
}

template <typename T>
void test_trifusion(T* tab, int taille) {
  int debut = 0;
  int fin = taille - 1;
  trifusion(tab, debut, fin);
}

int main() {
  int tab[] = {9, 1, 10, 7, 4, 8, 5, 3, 6, 2};
  //int tab[] = {7, 12, 3, 2, 4, 18, 1, 6};
  int taille = sizeof(tab) / sizeof(*tab);
  test_trifusion(tab, taille);
}
