/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Les Pointeurs
*/

#include <iostream>

using namespace std;

int main() {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int* pa = &a;
  int* pb = &b;
  int* pc = &c;
  int* pd = &d;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "pa = " << pa << " pb = " << pb << " pc = " << pc << " pd = " << pd << endl;

  *pa = 4;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "pa = " << pa << " pb = " << pb << " pc = " << pc << " pd = " << pd << endl;

  pa = pb;
  *pa = 8;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "pa = " << pa << " pb = " << pb << " pc = " << pc << " pd = " << pd << endl;

  c = 10;
  d += *pd;
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
  cout << "pa = " << pa << " pb = " << pb << " pc = " << pc << " pd = " << pd << endl;

  return 0;
}
