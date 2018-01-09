# 1 Connaissances techniques et C++

## (a)

La ligne 10 du programme question1a.cpp,

`int* t = new int[8];`

déclare sur la pile un pointeur vers un entier (t)
alloue dynamiquement un tableau d'entiers de 8 cases sur le tas.
affecte à t l'adresse du tableau

## (c)
 0 3 5 7 5 ? ? ? : 16

## (d)
`delete[] t; // entre lignes 19 et 20`

## (e)
Les 2 programmes affichent le même résultat.
alice
* foo() : passage par copie de pointeur vers une pile
* l'appel de depiler affecte la pile originale
bob
* foo() : passage par copie de la pile
* l'appel de depiler n'affecte pas la pile originale

## (f)
* l'avantage de la solution d'Alice est quelle évite de copier la pile au complet lors de l'appel de foo()
* la solution de Bob permet de calculer la somme sans changer la pile originale
