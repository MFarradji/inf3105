/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 2 - Question d'examen antérieur
*/

#include <iostream>

using namespace std;

class Allo {
  public:
    int x;

    Allo(int x_ = 0) : x(x_) {
      cout << "A" << x << " ";
    }

    Allo(const Allo& autre) : x(autre.x) {
      cout << "B" << x << " ";
    }

    ~Allo() {
      cout << "C" << x << " ";
    }
};

void f1(Allo a1 , Allo& a2, Allo* a3) {
  a1.x++; // effet local
  a2.x--; // équivaut à a.x--
  a3 += 1; // a3 = tab[2]
  (a3->x) += 2000;
}

int main() {
  Allo tab[3];
  Allo a(20);
  Allo* b = new Allo(5);
  Allo* c = tab + 1;
  f1(a, *b, c);
  cout << endl << "-------" << endl;
  Allo* t = new Allo[4];
  t[2] = Allo(9);
  cout << endl;
  delete b;
  delete[] t;
  return 0;
}
