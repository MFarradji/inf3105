#include <iostream>

using namespace std;

void echanger(int&, int&);

int main(int argc, char* argv[]) {
  int y = 12;
  int z = 18;

  cout << "y = " << y << " z = " << z << endl;
  echanger(y, z);
  cout << "y = " << y << " z = " << z << endl;

  return 0;
}

void echanger(int& x1, int& x2) {
  int temp = x1;
  x1 = x2;
  x2 = temp;
}
