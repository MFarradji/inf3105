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
3. Toutes les sentinelles (NIL) sont noires
4. Si un noeud est rouge, alors ses 2 enfants sont noirs
5. Chaque chemin partant d'un noeud vers ses sentinelles descendantes contient le même nombre de noeuds noirs.

## Exemple
<img src="https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg" width="675" height="325">
