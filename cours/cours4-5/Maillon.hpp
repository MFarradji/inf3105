#ifndef _MAILLON_HPP
#define _MAILLON_HPP
template <typename T>
class Maillon<T> {
  protected:
    T* _element;
    Maillon<T>* _suivant;
  public:
    Maillon(void);
    Maillon(const Maillon<T>&);
    Maillon(T* a_element, Maillon<T>* a_suivant = 0); // valeurs par défaut en dernier
    virtual ~Maillon(void);
    T* element(void) const;
    void element(T* a_element);
    Maillon<T>* suivant(void) const;
    void suivant(Maillon<T>* a_suivant);
};
#endif
