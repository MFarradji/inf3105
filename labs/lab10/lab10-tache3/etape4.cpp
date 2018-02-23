/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 4 : l'héritage et les tableaux statiques.

   Est-ce que etape3.cpp compile?
    --> NON
   Quel est le message d'erreur?
     --> etape.cpp:44:22: erreur: no matching function for call to ‘Personne::Personne()’
   Pourquoi?
    --> à la ligne Personne equipe[5]; le compilateur doit construire les 5 objets.

   Solution:
    --> Ajouter un constructeur sans argument.
*/


#include <iostream>
using namespace std;

class Personne{
  public:
    // Personne(); // On pourrait définir un constructeur sans argument.
    Personne(const string& nom="?"); // Une valeur par défaut permet de créer un constructeur sans argument.

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


//***** Début des définitions (implémentations des constructeurs et fonctions) *************/

Personne::Personne(const string& nom_)
 : nom(nom_)
{

}

void Personne::afficher() const{
    cout << "Personne: nom=" << nom << std::endl;
}



Etudiant::Etudiant(const string& nom_, const string& programme_, float moyenne_)
 : Personne(nom_), programme(programme_), moyenne(moyenne_)
{
}

void Etudiant::afficher() const{
    cout << "Etudiant: nom=" << nom << ", programme=" << programme << ", moyenne=" << moyenne << "/4.3" << std::endl;
}



Employe::Employe(const string& nom_, const string& departement_, float salaire_)
 : Personne(nom_), departement(departement_), salaire(salaire_)
{
}

void Employe::afficher() const{
    cout << "Employe: nom=" << nom << ", departement=" << departement << ", salaire=" << salaire << "$/an" << std::endl;
}

//***** Fin des définitions *************/

int main(){
    Personne equipe[5]; // tableau avec taille statique
    /* equipe[0] = Personne("marc");*/  // que contiendra equipe[0] ?
    equipe[1] = Etudiant("marie", "medecine", 4.1f);
    equipe[2] = Etudiant("jean", "informatique", 3.5);
    equipe[3] = Employe("robert", "finances", 62400);
    equipe[4] = Employe("anne", "ingenerie", 67400);

    for(int i=0;i<5;i++){
        cout << "[" << i << "] ";
        equipe[i].afficher();
    }

    // Que se passe-t-il ?
    // Indice 'Personne p2 = et1;' dans etape1.cpp et etape2.cpp

    return 0;
}

