# 4 Connaissances générales (5 points, -1 par mauvaise réponse)
(a) Vrai : dans un tableau linéaire et dynamique, un ajout peut dégénérer en temps O(n).

(b) faux : dans un tableau linéaire et dynamique, le temps amorti de l’ajout est toujours de O(1).

lorsque la capacité maximale est atteinte :
temps amorti = O(n) si on augmente la capacité d'un seul élément
temps amorti = O(1) si on double la capacité du tableau

(c) Vrai ou faux : dans un arbre rouge-noir, on peut avoir plusieurs nœuds rouges de suite sur un chemin vers une feuille.

(d) Quel est le temps d’exécution d’une fonction faisant le parcours en largeur d’un arbre général (pas nécessairement binaire) ? Utilisez la notation grand O et donnez une courte justification.

b = nombre de branches par arbre

h = hauteur de l'arbre

c = complexité temporelle

c = b + b² + b³ + ... + b^(h+1) = O(b^(h+1))

[Référence](https://mhesham.wordpress.com/tag/bfs-vs-dfs/)

(d) Vrai : un parcours en largeur s’implémente naturellement à l’aide d’une fonction récursive.

(e) Dans vos propres mots, définissez ce qu’est un type abstrait de données.

Un type général dont on ne connaît pas la valeur à l'avance.

(f) En une ou deux phrases, décrivez le rôle d’un destructeur de classe en C++ ?

* Libérer la mémoire allouée dynamiquement durant le cycle de vie de l'objet.
* Il est appelé lorsque l'objet n'est plus accessible ou l'instruction `delete` est appliquée sur un pointeur vers cette classe.
