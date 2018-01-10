#include <iostream>

using namespace std;

void afficher(int tab[], int taille);
int taille(int tab[]);
void triMonceau(int tab[], int taille);
void inserer(int tab[], int taille);
void supprimer(int tab[], int taille);
void supprimer(int tab[], int i);
void descendre(int tab[], int taille, int i);
void echanger(int tab[], int i, int j);

int main() {
  int tab[] = {7, 2, 5, 18, 3, -2, 14, 21, 8, 6, 27};
  int taille = sizeof(tab) / sizeof(*tab);
  cout << "tableau initial" << endl;
  afficher(tab, taille);
  triMonceau(tab, taille);
  cout << "tableau final" << endl;
  afficher(tab, taille);
}

void afficher(int tab[], int taille) {
  for (int i = 0; i < taille; ++i)
    cout << tab[i] << ' ';
  cout << endl;
}

void triMonceau(int tab[], int taille) {
  cout << "insertion" << endl;
  for (int i = 0; i < taille; ++i) {
    inserer(tab, i);
    afficher(tab, taille);
  }
  cout << "supression" << endl;
  for (int i = taille - 1; i > 0; --i) {
    supprimer(tab, i);
    afficher(tab, taille);
  }
}

void inserer(int tab[], int i) {
  if (i != 0) {
    int parent = (i - 1) / 2;
    if (tab[i] > tab[parent]) {
      echanger(tab, i, parent);
      inserer(tab, parent);
    }
  }
}

void supprimer(int tab[], int i) {
  echanger(tab, 0, i);
  descendre(tab, i, 0);
}

void descendre(int tab[], int taille, int i) {
  //afficher(tab, taille);
  int suivant = 2 * i + 1; // enfant 1
  if (suivant < taille) {
    if (suivant + 1 < taille && tab[suivant + 1] > tab[suivant])
      ++suivant; // enfant 2
    if (tab[suivant] > tab[i]) {
      echanger(tab, i, suivant);
      descendre(tab, taille, suivant);
    }
  }
}

void echanger(int tab[], int i, int j) {
  int temp = tab[i];
  tab[i] = tab[j];
  tab[j] = temp;
}
