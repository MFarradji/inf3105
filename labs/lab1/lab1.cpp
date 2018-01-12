/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 1
*/

#include <iostream>
#include <limits>

#include "point.h"

using namespace std;

int main(void) {
  int n;
  cin >> n;
  Point* tableau = new Point[n];
  double min = numeric_limits<double>::infinity();

  for (int i = 0; i < n; i++) {
    cin >> tableau[i];
    for (int j = 0; j < i; j++) {
      double distance = tableau[i].distance(tableau[j]);
      if (distance < min) {
        min = distance;
      }
    }
  }

  cout << "distance entre les 2 points les plus proches: " << min << endl;
  delete[] tableau;
  return 0;
}
