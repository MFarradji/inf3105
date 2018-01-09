#include <iostream>
#include "Fraction.hpp"

using namespace std;

Fraction::Fraction(void) {
  _numerateur = 0;
  _denominateur = 1;
  cout << "Fraction::Fraction(void)" << endl;
}

Fraction::Fraction(const Fraction& a_f) {
  _numerateur = a_f._numerateur;
  _denominateur = a_f._denominateur;
  cout << "Fraction::Fraction(const Fraction& a_f)" << endl;
}

Fraction::Fraction(int a_num, int a_den) {
  _numerateur = a_num;
  _denominateur = a_den;
  cout << "Fraction::Fraction(int a_num, int a_den)" << endl;
}

Fraction::~Fraction(void) {
  cout << "Fraction::~Fraction(void)" << endl;
}

ostream& operator << (ostream& a_sorties, const Fraction& a_fraction) {
  a_sorties << a_fraction._numerateur << "/" << a_fraction._denominateur;
  return a_sorties;
}
