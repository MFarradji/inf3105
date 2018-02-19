# Arbre rouge-noir

Un arbre rouge-noir est un arbre binare de recherche (ABR) balancé.

## Complexité temporelle
| Algorithme | Complexité |
| :---: | :---: |
| Recherche | O(log n) |
| Insertion | O(log n) |
| Supression | O(log n) |

## Propriétés
1. Chaque noeud est rouge ou noir.
2. La racine est noire.
3. Toutes les sentinelles (NIL) sont noires.
4. Si un noeud est rouge, alors ses 2 enfants sont noirs.
5. Chaque chemin partant d'un noeud vers ses sentinelles descendantes contient le même nombre de noeuds noirs (hauteur noire).

## Exemple
<img src="https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg" width="675" height="325">

## Notation
| Étiquette | Signification |
| :---: | :---: |
| N | noeud courant |
| P | noeud parent de N |
| G | noeud grandparent de N (parent de P) |
| S | noeud frère de N (enfant de P) |
| U | noeud oncle de N (enfant de G) |

* Dans le cas 6 de la suppression, un noeud blanc représente un noeud rouge ou noir.
* Un triangle numéroté représente un sous-arbre de profondeur indéterminée. Un cercle noir au dessus du triangle indique que sa profondeur est plus grande de 1 par rapport à un autre triangle sans cercle.

## Insertion

* Insérer un noeud N comme dans un ABR non équilibré.
* Colorier le noeud N rouge et lui ajouter 2 sentinelles.
* Rééquilibrer l'arbre si nécessaire selon 4 cas possibles.

### Cas 1 : N est la racine de l'arbre

Ce cas permet de corriger la propriété #2 (la racine est noire).

Changer la couleur de N pour noir.

### Cas 2 : P est noir

Il n'y a rien à faire, car les propriétés #4 et #5 sont respectées.

*Note : Pour les cas 3 et 4, P peut être l'enfant gauche ou droit de G. Les diagrammes montrent seulement le cas de gauche.*

### Cas 3 : P est rouge et U est rouge

Ce cas permet de corriger la propriété #5.

* Changer la couleur de P et U pour noir.
* Changer la couleur de G pour rouge.
* Revérifier les 4 cas, en prenant G comme nouveau noeud courant (N), car les propriétés #2 ou #4 pourraient être violées.

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d6/Red-black_tree_insert_case_3.svg" width="813" height="218">

### Cas 4 : P est rouge et U est noir

**Étape 1**

Si G, P et N sont en zigzag, faire une rotation sous P.

* Si P est à gauche de G et N est à droite de P, faire une rotation droite-gauche sous P.
* Sinon si P est à droite de G et N est à gauche de P, faire une rotation gauche-droite sous P.

Dans tous les cas, passer à l'étape 2 en prenant P comme noeud courant.

<img src="https://upload.wikimedia.org/wikipedia/commons/8/89/Red-black_tree_insert_case_4.svg" width="774" height="215">

**Étape 2**

* Si N est l'enfant gauche de P, faire une rotation gauche-droite sous G.
* Sinon N est l'enfant droit de P. Faire une rotation droite-gauche sous G.
* Change la couleur de P pour noir.
* Changer la couleur de G pour rouge.

<img src="https://upload.wikimedia.org/wikipedia/commons/d/dc/Red-black_tree_insert_case_5.svg" width="841" height="245">
