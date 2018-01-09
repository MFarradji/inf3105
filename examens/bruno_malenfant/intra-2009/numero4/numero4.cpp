#include <iostream>

using namespace std;

class C {
  public:
    C(int a_a = 0 ) :
    a(a_a) {};
    virtual ~C() {}
    C* f() {
      C* r = this;
      r++;
      return r;
    }
    friend ostream& operator << (ostream&, C&);
  private:
    int a;
};

ostream& operator << (ostream& a_cout, C& a_c) {
  a_cout << a_c.a;
  return a_cout;
}

int main() {
  C t[10];
  int i = 0;
  for (i = 0; i < 10; i++) {
    t[i] = C(10 - i);
  }

  C* k = t + 3;
  cout << *k << " ";
  *(k + 1) = *(k - 1);
  cout << k[1] << " ";
  k = k->f();
  cout << k[0] << endl;

  return 0;
}
