#include <iostream>

using namespace std;

void echanger(int*, int*);

int main(int argc, char* argv[]) {
  int y = 12;
  int z = 18;
  int tab[10];

  for (int i = 0; i < 10; i++)
    tab[i] = i;

  cout << "y = " << y << " z = " << z << endl;
  echanger(&y, &z);
  cout << "y = " << y << " z = " << z << endl;

  cout << "tab[3] = " << tab[3] << " tab[6] = " << tab[6] << endl;
  echanger(tab + 3, tab + 6);
  cout << "tab[3] = " << tab[3] << " tab[6] = " << tab[6] << endl;

  return 0;
}

void echanger(int* x1, int* x2) {
  int temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}
