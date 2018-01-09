#if !defined(LISTE_HPP)
#define LISTE_HPP

template <class T>
class Liste {
  private:
    Cellule* premiere;
    class Cellule {
      public:
        Cellule* precedente;
        Cellule* suivante;
        T element;

        Cellule(const T& e, Cellule* s, Cellule *p) : precedente(p), suivante(s), {
          element = e;
        }
    };
  public:
    Liste() {
      premiere = nullptr;
    }
    ~Liste();
    Liste inverse() const;
};

#endif
