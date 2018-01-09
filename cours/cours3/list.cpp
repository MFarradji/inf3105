#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> liste;
  for (int i = 1; i <= 10; i++)
    liste.push_front(i);

  for (list<int>::iterator it = liste.begin(); it != liste.end(); it++)
    cout << *it << " ";
  cout << endl;

  liste.sort();
  liste.remove(5);

  for (list<int>::iterator it = liste.begin(); it != liste.end(); it++)
    cout << *it << " ";

  return 0;
}
