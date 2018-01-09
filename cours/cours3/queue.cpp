#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> file;
  int somme = 0;
  for (int i = 1; i <= 5; i++)
    file.push(i);

  while (!file.empty()) {
    int devant = file.front();
    cout << devant << endl;
    somme += devant;
    file.pop();
  }

  cout << "somme = " << somme << endl;
  return 0;
}
