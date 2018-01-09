#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main() {
  stack< int, list<int> > pile;
  int somme = 0;
  for (int i = 1; i <= 5; i++)
    pile.push(i);

  while (!pile.empty()) {
    int valeurSommet = pile.top();
    cout << valeurSommet << endl;
    somme += valeurSommet;
    pile.pop();
  }

  cout << "somme = " << somme << endl;
  return 0;
}
