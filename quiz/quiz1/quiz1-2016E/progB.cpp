/* INF3105 / 2016E / Quiz 1 */
#include <iostream>
#include "tableau.h"

using namespace std;

// PROGRAMME B
bool fb(int x, const Tableau<int>& t, int i = 0, int s = 0) {
  if (x == s) return true;
  if (i >= t.taille()) return false;
  if (fb(x, t, i + 1, s)) return true;
  if (fb(x, t, i + 1, s + t[i])) {
    cout << t[i] << ' ';
    return true;
  }
  return false;
}

int main(int argc, const char** argv) {
  int x = 0;
  cout << "x: ";
  cin >> x;
  cout << "Entrez des nombres " << "(zéro pour arrêter):";
  Tableau<int> tab;
  while (true) {
    int nombre = 0;
    cin >> nombre;
    if (nombre == 0) break;
    tab.ajouter(nombre);
  }
  if (fb(x, tab))
    cout << "Eureka!"<< endl;
  return 0;
}
