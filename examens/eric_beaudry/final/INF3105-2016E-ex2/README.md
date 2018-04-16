# INF3105 - Final Été 2016

## 1 Monceaux
a)
<pre>
7

  7
 /
8

  1
 / \
8   7

    1
   / \
  5   7
 /
8

    1
   / \
  5   7
 / \
8   9

     1
    / \
   /   \
  5     7
 / \   /
8   9 10

     1
    / \
   /   \
  5     5
 / \   / \
8   9 10  7

</pre>

b)

```cpp
template <class T>
class Monceau {
  private:
    vector<T> tab;
    void echanger(int i, int j);
  public:
    void supprimerMin();
};

template <class T>
T Monceau::enleverMin() {
  T min = tab[0];
  echanger(0, tab.size() - 1);
  tab.pop_back();
  unsigned indice = 0;
  bool descendre = false;
  do {
    unsigned suivant = 2 * indice + 1;
    descendre = suivant < tab.size();
    if (descendre) {
      if (suivant + 1 < tab.size() && tab[suivant + 1] < tab[suivant])
        ++suivant;
      descendre = tab[suivant] < tab[indice];
      if (descendre) {
        echanger(suivant, indice);
        indice = suivant;
      }
    }
  } while(descendre);
  return min;
}

template <class T>
void Monceau::echanger(int i, int j) {
  T temp = tab[i];
  tab[i] = tab[j];
  tab[j] = temp;
}
```

## 2 Arbres binaires de recherche vs Table de hachage
a)
### main1
* cas moyen: O(n log m)
* pire cas: O(n log m)

### main2
* cas moyen: O(n)
* pire cas: O(n^2)

b) Tous les mots différents sont en collision (même index), insertion dans une liste simplement chaînée.

c) main 2 car le cas moyen est meilleur

d) main1: mots affichés en ordre alphabétique, main2: mots affichés en ordre indéfini

## 3 Table de hachage
a)
```cpp
template <class K, class V>
V& Dictionnaire<K, V>::operator[](const K& k) {
  int c = k.hash() % nbCasiers;
  Entree* courante = casiers[c];
  while (courante != nullptr) {
    if (courante->cle == k) {
      return courante->valeur;
    }
    courante = courante->suivante;
  }
  courante = new Entree(k);
  return courante->valeur;
}
```

b) voir solution officielle

## 4 Graphes / Représentation et simulation d'algorithmes

a) voir solution officielle

b) profondeur : {d,b,a,c,e}
largeur : {d,b,e,a,c}

c) voir solution officielle

d) Oui car tout les noeuds sont atteignables à partir de n'importe quel noeud.

## 5 Graphes / Analyse de la complexité

* ligne 4, boucle while, O(n)
* ligne 8, boucle for, O(n)
* ligne 9, at, O(log(n))
* ligne 10, boucle for imbriquée, O(m / n) en moyenne
* ligne 11, find, O(log (n))
* complexité totale = O(n^2 * log(n) + n * log(n) * m)

## 6 Graphes / Résolution d'un problème
voir solution officielle
