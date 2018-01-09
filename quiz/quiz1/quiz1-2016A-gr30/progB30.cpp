/* Programme B pour groupe 30 */
#include <iostream>
using namespace std;
int c1=0, c2=0, c3=0, c4=0;

class A{
  public:
    A() : x(0.0) {c1++;}
    A(double x_) : x(x_) {}
    ~A(){c2++;}
  private:
    double x;
};

class B{
  public:
    B(){c3++;}
    ~B(){c4++;}
  private:
    A a1, a2;
};

void fB(){
   A a1(1.5), a2;
   B b1;
   B* b2 = &b1;
   B* b3 = new B[2];
}

int main(){
  fB();
  cout << "c1=" << c1 << '\t'
       << "c2=" << c2 << '\t'
       << "c3=" << c3 << '\t'
       << "c4=" << c4 << endl;
  return 0;
}

