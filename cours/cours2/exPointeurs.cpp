#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int x = 12;
  int *p = &x;
  cout << "x = " << x << endl;
  cout << "adresse de x = " << p << endl;
  *p = 18;
  cout << "x = " << x << endl;
  int y = 7;
  p = &y;
  cout << "adresse de y = " << p << endl;
  cout << "y = " << y << endl;

  int** q;
  q = &p;
  cout << "adresse de p = " << q << endl;
  cout << "p = " << p << endl;

  int* r = &x;
  q = &r;
  **q = 17;

  cout << "x = " << x << endl;

  return 0;
}
