/*
  INF3105 - Structures de donnees et algorithmes
  UQAM / Departement d'informatique
*/

#include <iostream>
#include <stdlib.h>
#include "file.h"

using namespace std;

void test1();
void test2();

int main() {
  test1();
  test2();
  return 0;
}

void test1() {
  cout << "Test #1 : Test de la file (operations de base)" << endl;
  File<int> file1;
  file1.enfiler(1);
  file1.enfiler(4);
  file1.enfiler(2);

  if (file1.defiler() != 1)
    cout << "1 >> Erreur" << endl;
  if (file1.defiler() != 4)
    cout << "2 >> Erreur" << endl;
  if (file1.defiler() != 2)
    cout << "3 >> Erreur" << endl;
  if (!file1.vide())
    cout << "4 >> Erreur" << endl;

  file1.enfiler(13);
  if (file1.vide())
    cout << "5 >> Erreur" << endl;
  if (file1.defiler() != 13)
    cout << "6 >> Erreur" << endl;
  if (!file1.vide())
    cout << "7 >> Erreur" << endl;

  File<int> file2;
  file2.enfiler(13);
  if (file2.vide())
    cout << "8 >> Erreur" << endl;
  if (file2.defiler() != 13)
    cout << "9 >> Erreur" << endl;
  if (!file2.vide())
    cout << "10 >> Erreur" << endl;

  cout << "-------- Fin #1 --------------" << endl;
}

void test2() {
  cout << "Test #2 : Test de la file (operateur =)" << endl;
  File<int> file1;
  file1.enfiler(1);
  file1.enfiler(4);
  file1.enfiler(2);

  File<int> file2;
  file2.enfiler(20);
  file2.enfiler(21);

  file2 = file1;
  file1.enfiler(10);

  if (file1.defiler() != 1)
    cout << "1 >> Erreur" << endl;
  if (file1.defiler() != 4)
    cout << "2 >> Erreur" << endl;
  if (file1.defiler() != 2)
    cout << "3 >> Erreur" << endl;
  if (file1.vide())
    cout << "4 >> Erreur" << endl;

  file2 = file1;
  
  if (file2.defiler() != 10)
    cout << "5 >> Erreur" << endl;
  if (!file2.vide())
    cout << "6 >> Erreur" << endl;
  if (file1.vide())
    cout << "7 >> Erreur" << endl;

  cout << "-------- Fin #2 --------------" << endl;
}
