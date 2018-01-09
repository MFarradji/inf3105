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
  cout << "a.x = " << a.x << " a.y = " << a.y << endl;
  cout << "b.x = " << b.x << " b.y = " << b.y << endl;

  A a2(a);
  B b2(b);
  cout << "a2.x = " << a2.x << " a2.y = " << a2.y << endl;
  cout << "b2.x = " << b2.x << " b2.y = " << b2.y << endl;

  cout << "j = " << j << " r = " << r << endl;
  cout << "s2 = " << s2 << " s3 = " << s3 << endl << endl;

  cout << "i = " << i << " c = " << c << endl;
  //cout << "p = " << *p << endl;
  //cout << " d = " << **d << endl;
  cout << "s1.length() = " << s1.length() << endl;
  return 0;
}
