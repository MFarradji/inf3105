#include <string>
#include <map>
#include <vector>

using namespace std;

template <typename T>
class Sommet {
  public:
    string identification;
    T information;
};

template <typename T>
class ListeAdjacence {
  private:
    vector< Sommet<T> > _liste;
  public:
    void ajouterElement(const Sommet<T>& a_sommet);
    bool appartient(const Sommet<T>& a_sommet) const;
};

template <typename T>
class Graphe {
  private:
    map< Sommet<T>, ListeAdjacence<T> > description;
  public:
    void ajouterArc(const Sommet<T>& a_sommet1, const Sommet<T>& a_sommet2);
    vector< Sommet<T> > voisins(const Sommet<T>& a_sommet) const;
    bool sontVoisins(const Sommet<T>& a_sommet1, const Sommet<T>& a_sommet2);
};

template <typename T>
bool ListeAdjacence<T>::appartient(const Sommet<T>& a_sommet) const {
  bool existe = false;
  for (int i = 0; i < _liste.size() && !existe; ++i)
    existe = _liste[i] == a_sommet;
  return existe;
}

template <typename T>
bool Graphe<T>::sontVoisins(const Sommet<T>& a_sommet1, const Sommet<T>& a_sommet2) {
  return description[a_sommet1].appartient(a_sommet2) || description[a_sommet2].appartient(a_sommet1);
}
