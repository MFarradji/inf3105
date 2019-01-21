<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Arbre rouge-noir](#arbre-rouge-noir)
  - [Complexité temporelle](#complexit%C3%A9-temporelle)
  - [Propriétés](#propri%C3%A9t%C3%A9s)
  - [Exemple](#exemple)
  - [Notation](#notation)
  - [Insertion](#insertion)
    - [Cas 1 : N est la racine de l'arbre](#cas-1--n-est-la-racine-de-larbre)
    - [Cas 2 : P est noir](#cas-2--p-est-noir)
    - [Cas 3 : P est rouge et U est rouge](#cas-3--p-est-rouge-et-u-est-rouge)
    - [Cas 4 : P est rouge et U est noir](#cas-4--p-est-rouge-et-u-est-noir)
  - [Supression](#supression)
    - [Cas 1 : N est la racine de l'arbre](#cas-1--n-est-la-racine-de-larbre-1)
    - [Cas 2 : S est rouge](#cas-2--s-est-rouge)
    - [Cas 3](#cas-3)
    - [Cas 4](#cas-4)
    - [Cas 5](#cas-5)
    - [Cas 6](#cas-6)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Arbre rouge-noir

Un arbre rouge-noir est un arbre binaire de recherche (ABR) balancé.

## Complexité temporelle
n correspond au nombre noeuds dans l'arbre.

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

## Exemple
<img src="https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg" width="675" height="325">

## Notation
| Étiquette | Signification |
| :---: | :---: |
| N | noeud courant |
| P | noeud parent de N |
| G | noeud grand-parent de N (parent de P) |
| S | noeud frère de N (enfant de P) |
| U | noeud oncle de N (enfant de G) |
| S<sub>L</sub> | enfant gauche de S |
| S<sub>R</sub> | enfant droit de S |

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

## Supression

1. Trouver le noeud à effacer avec une recherche binaire.
2. Si le noeud a 2 enfants, le remplacer par son successeur ou prédecesseur, puis effacer le successeur ou prédecesseur.
3. Rendu à ce point, le noeud à effacer a 1 ou 2 sentinelles.
4. Si le noeud est rouge, le supprimer.
5. Sinon si le noeud est noir et son enfant est rouge, promouvoir l'enfant et le recolorer en noir.
6. Sinon c'est que le noeud est noir avec 2 sentinelles, 6 cas sont posssibles.

### Cas 1 : N est la racine de l'arbre

* Si N est la racine, il n'y rien à faire.
* Sinon passer au cas 2.

*Note: Dans les cas 2, 5 et 6, le cas où N est l'enfant gauche de P est considéré. Dans le cas où N est l'enfant droit, la gauche et la droite devraient être inversées.*

### Cas 2 : S est rouge

* Si S est rouge :
  * Si N est l'enfant gauche de P :
    * Faire une rotation droite-gauche sous P.
  * Sinon N est l'enfant droit de P :
    * Faire une rotation gauche-droite sous P.
  * Changer la couleur de P pour rouge.
  * Changer la couleur de S pour noir.
* Passer au cas 3.

<img src="https://upload.wikimedia.org/wikipedia/commons/5/5c/Red-black_tree_delete_case_2_as_svg.svg" width="619" height="235">

### Cas 3

* Si P, S, S<sub>L</sub> et S<sub>R</sub> sont noirs :
  * Changer la couleur de S pour rouge.
  * Revenir au cas 1 en prenant le parent de N comme nouveau N.
* Sinon passer au cas 4.

<img src="https://upload.wikimedia.org/wikipedia/commons/a/a0/Red-black_tree_delete_case_3_as_svg.svg" width="623" height="239">

### Cas 4

* Si P est rouge et S, S<sub>L</sub> et S<sub>R</sub> sont noirs :
  * Changer la couleur de S pour rouge.
  * Changer la couleur de P pour noir.
* Sinon passer au cas 5.

<img src="https://upload.wikimedia.org/wikipedia/commons/3/3d/Red-black_tree_delete_case_4_as_svg.svg" width="624" height="237">

### Cas 5

* Si S est noir :
  * Si N est l'enfant gauche de P, S<sub>L</sub> est rouge et S<sub>R</sub> est noir :
    * Faire une rotation gauche-droite sous S.
    * Changer la couleur de S pour rouge.
    * Change la couleur de S<sub>L</sub> pour noir.
  * Sinon si  N est l'enfant droit de P, S<sub>L</sub> est noir et S<sub>R</sub> est rouge :
    * Faire une rotation droite-gauche sous S.
    * Changer la couleur de S pour rouge.
    * Change la couleur de S<sub>R</sub> pour noir.
* Passer au cas 6.

<img src="https://upload.wikimedia.org/wikipedia/commons/3/36/Red-black_tree_delete_case_5_as_svg.svg" width="453" height="258">

### Cas 6

* Changer la couleur de S pour celle de P.
* Changer la couleur de P pour noir.
* Si N est l'enfant gauche de P :
  * Faire une rotation droite-gauche sous P.
  * Changer la couleur de S<sub>R</sub> pour noir.
* Sinon, N est l'enfant droit de P :
  * Faire une rotation gauche-droite sous P.
  * Changer la couleur de S<sub>L</sub> pour noir.

<img src="https://upload.wikimedia.org/wikipedia/commons/9/99/Red-black_tree_delete_case_6_as_svg.svg" width="622" height="246">
