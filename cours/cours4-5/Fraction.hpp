#if !defined(FRACTION_HPP)
#define FRACTION_HPP

#include <iostream>

using namespace std;

class Fraction {
  private:
    int _numerateur;
    int _denominateur;
  public:
    // toujours écrire le constructeur sans argument et par copie
    Fraction(void);
    // Fraction(void) : _numerateur(0), _denominateur(1) {}
    Fraction(const Fraction&);
    Fraction(int, int);

    virtual ~Fraction(void);

    friend ostream& operator << (ostream&, const Fraction& a_fraction);
};

#endif
