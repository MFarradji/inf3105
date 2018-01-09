#include <iostream>

using namespace std;

// alloue une case en memoire dynamique
int* f();

int main(int argc, char* argv[]) {
  int* p = f();
  delete p;
  return 0;
}

int* f() {
  int* r = new int;
  return r;
}
