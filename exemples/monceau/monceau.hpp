#include <vector>

using namespace std;

class Monceau {
  private:
    vector<int> tab;
    
    void echanger(int i, int j);
  public:
    Monceau();
    void afficher();
    void inserer(int valeur);
    void supprimerMin();
    int min();
    bool estVide() const;
};