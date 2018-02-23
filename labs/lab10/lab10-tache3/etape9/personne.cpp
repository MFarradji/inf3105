/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 9 : séparation du code en plusieurs fichiers.
*/

#include <iostream>
#include "personne.h"

Personne::Personne(const string& nom_)
 : nom(nom_)  // après le : , ce sont des initialisations.
  // nom(nom_) signifit qu'on construit nom par copie de nom_
{

}

void Personne::afficher() const{
    cout << "Personne: nom=" << nom << std::endl;
}

Etudiant::Etudiant(const string& nom_, const string& programme_, float moyenne_)
 : Personne(nom_), programme(programme_), moyenne(moyenne_)
   //Personne(nom) : comme Etudiant dérive de Personne, il faut construire la partie Personne
   //                on appelle donc le constructeur Personne(const string&)
 {
 }

void Etudiant::afficher() const{
    cout << "Etudiant: nom=" << nom << ", programme=" << programme << ", moyenne=" << moyenne << "/4.3" << std::endl;
}

Employe::Employe(const string& nom_, const string& departement_, float salaire_)
 : Personne(nom_), departement(departement_), salaire(salaire_)
   //Personne(nom) : comme Etudiant dérive de Personne, il faut construire la partie Personne
   //                on appelle donc le constructeur Personne(const string&)
{
}

void Employe::afficher() const{
    cout << "Employe: nom=" << nom << ", departement=" << departement << ", salaire=" << salaire << "$/an" << std::endl;
}

