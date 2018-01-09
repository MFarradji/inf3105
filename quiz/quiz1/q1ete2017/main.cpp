#include <iostream>

using namespace std;

void proc(int* ch) {
  int* i = ch;
  int t[10] = {0,0,0,0,0,0,0,0,0,0};
  while ((*ch) != 0) {
    t[*ch] = t[*ch] + 1;
    ++ch;
  }

  int j;
  for (j = 0; j < 10; ++j) {
    while (t[j] != 0) {
      (*i) = j;
      ++i;
      t[j] = t[j] - 1;
    }
  }
}

int main() {
  int a[7] = {1, 5, 6, 3, 8, 2, 0};
  proc(a);
  int c;
  for (c = 0; c < 6; ++c)
    cout << " " << a[c];
}
