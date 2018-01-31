/******   Annexe A: progA.cpp   *****/

#include <iostream>

int compte = 0;
bool f1(int* tab, int n) {
  for (int i = 0; i < n; i++)
    for (int a = 0; a < i; a++)
      for (int b = i + 1; b < n; b++)
        if ((++compte>=0) && (tab[i] == tab[a] + tab[b]))
          return true;
   return false;
}

bool f2(int* tab, int n) {
  for (int i = 0; i < n; i++)
    if (tab[i] % 2 == 0)
      for (int j = i + 1; j < n; j++)
        if (tab[j] == tab[i])
          return true;
  return false;
}

bool f3(int* tab, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (i != j && i != k && j != k && tab[i] * tab[j] == tab[k])
           return true;
  return false;
}

int main(int argc, const char** argv){
  int n;
  std::cin >> n;
  int* tab = new int[n];
  for(int i = 0; i < n; i++)
    std::cin >> tab[i];
  if (f1(tab, n))
    std::cout << "F1" << std::endl;
  if (f2(tab, n))
    std::cout << "F2" << std::endl;
  if (f3(tab, n))
    std::cout << "F3" << std::endl;
  std::cout<< "compte = " << compte << std::endl;
  return 0;
}
