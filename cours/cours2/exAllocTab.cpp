#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int* tab = new int[10];
  delete[] tab;
  return 0;
}
