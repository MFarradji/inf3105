#include <iostream>

using namespace std;

class G {
  public:
    G() { cout << "G" << endl; };
    virtual ~G() { cout << "-G" << endl; };
};

class H : public G {
  public:
    H() : G() { cout << "H" << endl; };
    virtual ~H() { cout << "-H" << endl; };
};

class K {
  public:
    K() { cout << "K" << endl; };
    virtual ~K() { cout << "-K" << endl; };
};

class F : public H, public K { // H avant K
  public:
    F() : K(), H() { cout << "F" << endl; };
    virtual ~F() { cout << "-F" << endl; };
};

void t() {
  F f;
}

int main() {
  t();
  return 0;
}
