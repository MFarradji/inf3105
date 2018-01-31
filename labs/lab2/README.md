# Lab 2 : Pointeurs, références, classes, constructeurs et destructeurs

## Définitions

**pointeur**

Un pointeur est une variable qui contient l'adresse d'une autre variable.

**référence**

Une référence est un alias, c'est à dire, un autre nom pour une variable qui existe déjà.

## 1. Les Pointeurs
```cpp
int x = 0; // déclare une entier x initialisé à 0
int* px = &x; // déclare un pointeur vers un entier px initialisé à l'adresse de x
*px = 1; // change la valeur de x pour 1 avec l'opérateur d'indirection *
```

## 2. Les Références
```cpp
int& rx = x; // déclare un alias rx pour x
rx = 2; // change la valeur de x pour 2
int y = 3;
int& ry = y;
rx = ry; // change la valeur de rx pour la valeur de ry (3)
```

## 3. Types de passage de paramètres
```cpp
void fonction(int m, int* x, int& y, int*& z) {
  // ...
}

int i = 4;
int* j = &i;
int& k = i;
fonction(i, j, k, j);
```

Lors de l'appel de la fonction, le passage de paramètres se déroule ainsi.

* La valeur de i est copiée dans m
* Les variables i et m sont indépendantes l'une de l'autre.
* La valeur de j (l'adresse de i) est copiée dans x.
* j et x pointent vers la même variable (i).
* y est un alias pour i.
* z est un alias pour j (référence d'un pointeur)

## 4. Classes, constructeurs et destructeurs

**foo.hpp**
```cpp
// inclure le fichier foo.hpp 1 seule fois lors de la compilation
#pragma once

// déclaration de la classe Foo
class Foo {
  private:
    // les variables et méthodes déclarées en bas sont privées
    int i = 0; // initialisation possible avec c++11
    char c = 'a';

    void bar(); // prototype de la méthode bar

  public:
    // les variables et méthodes déclarées en bas sont publiques
    bool b = false;

    Foo(); // constructeur sans paramètres
    Foo(int j); // constructeur avec un paramètre
    Foo(const Foo& f); // constructeur par copie

    ~Foo(); // destructeur

    bool operator == (const Foo& f) const; // surcharge de l'opérateur ==

    double test(int k);
};
```

**foo.cpp**
```cpp
#include "foo.hpp"

// implémentations des méthodes de la classe Foo
Foo::Foo() {}

Foo::Foo(int j) : i(j) {}

Foo::Foo(const Foo& f) : i(f.i) {}

// implémentation de la méthode bar
void Foo::bar() {
  return;
}

Foo::~Foo() {
  // rien à faire car aucune allocation dynamique
}

bool Foo::operator == (const Foo& f) const {
  // vérifier s'il s'agit de la même instance
  if (this == &f) {
    return true;
  }

  return i == f.i;
}

double Foo::test(int k) {
  return 1.0;
}
```

## Sources
* [cplusplus.com](http://www.cplusplus.com/doc/tutorial/pointers/)
* [tutorialspoint.com](https://www.tutorialspoint.com/cplusplus/cpp_references.htm)
