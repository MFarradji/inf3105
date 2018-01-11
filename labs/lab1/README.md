# Lab 1 - S'initier à C++ et aux outils du cours

## Méthode pour trouver les 2 points les plus proches

ex. : nuage de 4 points p1, p2, p3 et p4

combinaisons possibles:

comparer p2 avec p1

comparer p3 avec p2 et p1

comparer p4 avec p3, p2 et p1

n = 4, nombre de comparaisons (c) = 3 + 2 + 1 = 6

n = 3, c = 3

n = 2, c = 1

etc.

suite arithmétique
ui = u0 + ir

u0 = 0, r = 1

ui = i

où i = 0..n-1

somme = nombre de comparaisons

somme = (i + 1) * (2u0 + ir) / 2

somme = (i + 1) * i / 2

pour i = n - 1

somme = n * (n - 1) / 2 

somme = (n² - n) / 2

ex. : n = 4, c = 6

## Références
* [Suite arithmétique](https://fr.wikipedia.org/wiki/Suite_arithm%C3%A9tique)
