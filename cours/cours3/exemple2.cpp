#include <iostream>
#include <vector>

using namespace std;

int main() {
  // pour retourner le vector dans une fonction (pointeur)
  vector<int> * pv = new vector<int>();
  (*pv).push_back(12);
  pv->push_back(13);
  cout << (*pv)[0] << endl;
  cout << (*pv)[1] << endl;
  cout << pv->size() << endl;
  cout << pv->at(0) << endl;
  delete pv;
  return 0;
}
