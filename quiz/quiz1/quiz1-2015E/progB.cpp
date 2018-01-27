#include <iostream>

using namespace std;

class A {
  public:
    int x, y;
};

class B {
  public:
    B() {
      cout << "B()" << endl;
    }
    ~B(){
      cout << "~B()" << endl;
    }
    int x, y;
};

int main() {
  int i;
  char c;
  int j(3);
  int* p;
  int** d;
  int& r = i;
  string s1;
  string s2 = "s2";
  string s3("s3");
  A a;
  B b;

  A a2(a);
  B b2(b);

  return 0;
}
