#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int* p = new int(12);

  cout << p << " = " << *p << endl;
  delete p;
  p = NULL;
  cout << p << endl;
  return 0;
}
