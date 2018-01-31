/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Les Références
*/

#include <iostream>

using namespace std;

int main() {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int& ra = a;
  int& rb = b;
  int* pc = &c;
  int* pd = &d;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "ra = " << ra << " rb = " << rb << " pc = " << pc << " pd = " << pd << endl;

  ra = 4;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "ra = " << ra << " rb = " << rb << " pc = " << pc << " pd = " << pd << endl;

  ra = rb; // copie de la valeur de rb dans ra
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "ra = " << ra << " rb = " << rb << " pc = " << pc << " pd = " << pd << endl;

  c = 10;
  d += *pd;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "ra = " << ra << " rb = " << rb << " pc = " << pc << " pd = " << pd << endl;

  return 0;
}
