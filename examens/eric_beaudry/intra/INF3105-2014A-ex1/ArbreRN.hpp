template <class T>
class ArbreRN {
public:
  ArbreRN();
  ~ArbreRN();

  const T* recherche(const T& element) const;
  void inserer(const T&);
  void enlever(const T&);
  int fonctionB() const;

private:
  class Noeud {
    public:
      Noeud(const T&);
      T contenu;
      enum Couleur{rouge, noir} couleur;
      Noeud *gauche = nullptr;
      Noeud *droite = nullptr;
  };
  Noeud* racine;

  // Fonctions internes.
  const T* recherche(Noeud*, const T&) const;
  bool inserer(Noeud*&, const T&);
  void enlever(Noeud*&, const T& e);
};
