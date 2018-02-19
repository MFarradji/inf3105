# Arbre rouge-noir

Un arbre rouge-noir est un arbre binare de recherche balancé.

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
5. Chaque chemin partant d'un noeud vers ses sentinelles descendantes contient le même nombre de noeuds noirs.

## Définition
La profondeur d'un noeud est le nombre de noeuds noirs sur le chemin de la racine vers ce noeud.

## Exemple
<img src="https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg" width="675" height="325">

## Notation
| Étiquette | Signification |
| :---: | :---: |
| N | noeud courant |
| P | noeud parent de N |
| G | noeud grandparent (parent de P) |
| S | noeud frère de N (enfant de P) |
| U | oncle de N (enfant de G) |


* Dans le cas 6 de la suppression, un noeud blanc représente un noeud rouge ou noir.
* Un triangle numéroté représente un sous-arbre de profondeur indéterminée. Un cercle noir au dessus du triangle indique que sa profondeur est plus grande de 1 par rapport à un autre triangle sans cercle.
