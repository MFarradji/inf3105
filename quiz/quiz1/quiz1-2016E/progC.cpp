/* INF3105 / 2016E / Quiz 1 */
#include <iostream>

using namespace std;

// Programme C
class A {
  public:
    A() { cout << "A"; }
    ~A() { cout << "X"; }
};

class B {
  public:
    B() { cout << "B"; }
    ~B() { cout << "Z"; }
  private:
    A a1;
};

int main() {
  B b1;
  A* a1 = new A();
  B* b2 = new B();
  delete a1;
  b2 = NULL;
  return 1;
}
