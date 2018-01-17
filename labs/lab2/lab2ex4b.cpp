/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Classes, constructeurs et desctructeurs
*/

#include "point.hpp"

using namespace std;

void test(Point p1, Point& p2, const Point& p3, Point* p4) {
  cout << p1 << endl;
  p1 = p2; // effet local
  *p4 = p3; // copie les attributs (x, y) de c dans d
  p4 = &p1; // effet local
}

int main() {
  Point a;
  Point b(3, 4);
  Point c(0, 5);
  Point* d = new Point(5, 0);
  test(a, b, c, d);
  cout << a << " " << b << " " << c << " " << *d << endl;
  delete d;
  return 0;
}
