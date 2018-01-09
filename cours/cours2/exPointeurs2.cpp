#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int tab[10];
  int* p = tab;

  for (int i = 0; i < 10; i++)
    tab[i] = 0;

  *tab = 12;
  *(tab + 1) = 7;
  *(p + 3) = 5;
  p[7] = 21;
  ++p;
  p[4] = 8;
  p[-1] = 100;

  for (int i = 0; i < 10; i++)
    cout << tab[i] << " ";
  cout << endl;

  return 0;
}
