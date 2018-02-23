/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 9 : séparation du code en plusieurs fichiers.
*/

#if !defined(__PERSONNE_H__)
#define __PERSONNE_H__

#include <string>

using namespace std;

class Personne{
  public:
    Personne(const string& nom="?"); // ou mettre une valeur par défault ici afin de créer un sans argument
  
    virtual void afficher() const;
    
  protected:
    string nom;
};

class Etudiant : public Personne{
  public:
    Etudiant(const string& nom_, const string& programme_, float moyenne_);
    
    virtual void afficher() const;
    
  protected:
    string programme;
    float moyenne;
};

class Employe : public Personne{
  public:
    Employe(const string& nom_, const string& departement_, float salaire_);
    
    void afficher() const;
    
  protected:
    string departement;
    float salaire;
};

#endif

