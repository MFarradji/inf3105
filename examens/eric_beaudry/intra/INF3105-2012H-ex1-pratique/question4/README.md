# 4 Connaissances générales (5 points, -1 par mauvaise réponse)
(a) Vrai car on doit décaler les éléments vers la gauche lors d'une insertion. Dans le pire cas (insertion au début), il faudra décaler touts les éléments.

(b) faux

lorsque la capacité maximale est atteinte :
temps amorti = O(n) si on augmente la capacité d'un seul élément
temps amorti = O(1) si on double la capacité du tableau

(c) faux par définition de l'arbre rouge-noir

(d) O(V + E)
V : nombre de noeuds
E : nombre d'arrêtes
Justification : Le parcours en largeur parcours tous les noeuds de l'arbre.

[Référence](https://en.wikipedia.org/wiki/Breadth-first_search#Time_and_space_complexity)

(d) Vrai : un parcours en largeur s’implémente naturellement à l’aide d’une fonction récursive.

(e) Un type abstrait de données est un type décrit par sont fonctionnement externe, du point de vue de l'utilisateur et non de l'implémentation.

(f) En une ou deux phrases, décrivez le rôle d’un destructeur de classe en C++ ?

* Libérer la mémoire allouée dynamiquement durant le cycle de vie de l'objet.
* Il est appelé lorsque l'instruction `delete` est appliquée sur un pointeur vers cette classe.
