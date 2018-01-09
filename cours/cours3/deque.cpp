#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> d;
  for (int i = 0; i < 12; ++i)
    d.push_back(i);
  d.erase(d.begin());
  d.erase(d.end());
  deque<int>::iterator fin = d.end();
  for (deque<int>::iterator it = d.begin(); it != fin; ++it)
    cout << *it << endl;
  return 0;
}
