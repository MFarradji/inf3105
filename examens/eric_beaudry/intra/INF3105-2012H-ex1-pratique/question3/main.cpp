#include <iostream>
#include "Historique.hpp"

using namespace std;

int main() {
  Historique historique;
  historique.ajouter(0.00, 9.7);
  historique.ajouter(1.00, 10.1);
  historique.ajouter(2.00, 10.2);
  historique.ajouter(3.00, 10.5);
  historique.ajouter(4.00, 10.3);
  historique.ajouter(5.00, 10.7);
  historique.ajouter(6.01, 11.7);
  historique.ajouter(7.00, 12.4);
  historique.ajouter(8.01, 14.7);

  double date = 0.5;
  cout << "temperature estimee pour " << date << " = " << historique.estimeTemperature(date) << endl;
  date = 3.5;
  cout << "temperature estimee pour " << date << " = " << historique.estimeTemperature(date) << endl;

  double dateDebut = 0.99;
  double dateFin = 7.01;
  cout << "moyenne entre [" << dateDebut << ";" << dateFin << "] = " <<
          historique.calculeMoyenne(dateDebut, dateFin) << endl;

  dateDebut = 1.00;
  dateFin = 7.00;
  cout << "moyenne entre [" << dateDebut << ";" << dateFin << "] = " <<
          historique.calculeMoyenne(dateDebut, dateFin) << endl;

  dateDebut = 1.01;
  dateFin = 6.99;
  cout << "moyenne entre [" << dateDebut << ";" << dateFin << "] = " <<
          historique.calculeMoyenne(dateDebut, dateFin) << endl;
}
