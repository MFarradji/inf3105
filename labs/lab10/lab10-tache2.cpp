#include <iostream>
#include <set>

using namespace std;

class Combinaison {
  public:
    void insert(int nombre);
  private:
    set<int> nombres;
  
  friend istream& operator >> (istream& is, Combinaison& c);
  friend ostream& operator << (ostream& os, const Combinaison& c);
  friend bool operator < (const Combinaison& c1, const Combinaison& c2);
};

void Combinaison::insert(int nombre) {
  nombres.insert(nombre);
}

bool operator < (const Combinaison& c1, const Combinaison& c2){
  return c1.nombres < c2.nombres;
}

istream& operator >> (istream& is, Combinaison& c){
  int nombre;
  for (int i = 0; i < 6; i++) {
    is >> nombre;
    if (is) {
      c.insert(nombre);
    }
  }

  return is;
}

ostream& operator << (ostream& os, const Combinaison& c) {
  for (set<int>::iterator iter = c.nombres.begin(); iter != c.nombres.end(); ++iter) {
    os << *iter << " ";
  }
  return os;
}

int main() {
  set<Combinaison> mises;
  while (cin) {
    Combinaison combinaison_choisie;
    cin >> combinaison_choisie;
    if (!cin) {
      continue;
    }
    if (mises.find(combinaison_choisie) != mises.end()) {
      cout << "La combinaison " << combinaison_choisie << " est refusee!" << endl;
    } else {
      mises.insert(combinaison_choisie);
    }
  }

  cout << "Combinaisons choisies : " << endl;
  for (set<Combinaison>::iterator iter = mises.begin(); iter != mises.end(); ++iter) {
    cout << *iter << endl;
  }
}
