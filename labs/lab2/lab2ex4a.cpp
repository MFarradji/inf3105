#include "point.hpp"

using namespace std;

int main() {
  Point a;
  Point b(3, 4);
  cout << a.distance(b) << endl;
  return 0;
}
