#if !defined(HISTORIQUE_HPP)
#define HISTORIQUE_HPP

#include <vector>

using namespace std;

class Historique {
  private:
    class Couple {
      public:
        double date;
        double temperature;

        Couple(double date, double temperature) {
          this->date = date;
          this->temperature = temperature;
        };
    };
    vector<Couple> couples;
  public:
    Historique() {};
    ~Historique() {};
    void ajouter(double date, double temperature);
    double estimeTemperature(double date) const;
    double calculeMoyenne(double dateDebut, double dateFin) const;
};

#endif
