#if !defined(DHACHAGE_H)
#define DHACHAGE_H

using namespace std;

template <class K, class V>
class Dictionnaire {
  public:
    Dictionnaire(int capacite);
    ~Dictionnaire();

    V& operator[](const K&);

    long stats() const {
      return nbTentatives;
    }

  private:
    struct Casier {
      Casier();
      bool occupe;
      K cle;
      V valeur;
    };
    Casier* casiers;
    int nbCasiers;
    long nbTentatives;
};

template <class K, class V>
Dictionnaire<K, V>::Dictionnaire(int capacite) : nbCasiers(capacite), nbTentatives(0) {
  casiers = new Casier[nbCasiers];
}

template <class K, class V>
Dictionnaire<K, V>::~Dictionnaire() {
  delete[] casiers;
}

template <class K, class V>
Dictionnaire<K, V>::Casier::Casier() : occupe(false), valeur() {}

template <class K, class V>
V& Dictionnaire<K, V>::operator[](const K& k) {
  int c = k.hash() % nbCasiers;
  ++nbTentatives;
  while (casiers[c].occupe && casiers[c].cle != k) {
    if (c == nbCasiers - 1) {
      c = 0;
    } else {
      c++;
    }
    ++nbTentatives;
  }
  casiers[c].occupe = true;
  casiers[c].cle = k;
  return casiers[c].valeur;
}

#endif
