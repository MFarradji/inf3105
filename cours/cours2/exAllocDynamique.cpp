#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int* p = new int;
  *p = 0;
  int x = 12;

  cout << *p << endl;

  delete p;
  p = &x;

  cout << *p << endl;

  return 0;
}
