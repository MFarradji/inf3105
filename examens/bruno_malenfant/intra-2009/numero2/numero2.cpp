#include <iostream>

using namespace std;

class NombreComplexe {
  private:
    double reelle;
    double imaginaire;
  public:
    NombreComplexe(double a_reelle = 0.0, double a_imaginaire = 0.0) :
    reelle(a_reelle), imaginaire(a_imaginaire) {};
    virtual ~NombreComplexe();
    NombreComplexe operator * (const NombreComplexe&) const;
  friend ostream& operator << (ostream& os, const NombreComplexe&);
};

NombreComplexe::~NombreComplexe() {}

NombreComplexe NombreComplexe::operator * (const NombreComplexe& z2) const {
  return NombreComplexe(
    reelle * z2.reelle - imaginaire * z2.imaginaire,
    reelle * z2.imaginaire + imaginaire * z2.reelle
  );
}

ostream& operator << (ostream& os, const NombreComplexe& z) {
  os << z.reelle << " + "  << "i*" << z.imaginaire;
  return os;
}

int main() {
  NombreComplexe z1 = NombreComplexe(1.0, 2.0);
  NombreComplexe z2 = NombreComplexe(3.0, 4.0);
  NombreComplexe z3 = z1 * z2;
  cout << "z1 = " << z1 << endl;
  cout << "z2 = " << z2 << endl;
  cout << "z3 = " << z3 << endl;
  return 0;
}
