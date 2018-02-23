/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 3 : l'héritage et les tableaux statiques.

   Est-ce que ce code compile?
   Quel est le message d'erreur?
   Pourquoi? Réponse dans etape4.cpp
*/


#include <iostream>
using namespace std;

class Personne{
  public:
    Personne(const string& nom);
    virtual ~Personne(){};

    virtual void afficher() const;

  protected:
    string nom;
};

class Etudiant : public Personne{
  public:
    Etudiant(const string& nom_, const string& programme_, float moyenne_);
    virtual ~Etudiant(){};

    virtual void afficher() const;

  protected:
    string programme;
    float moyenne;
};

class Employe : public Personne{
  public:
    Employe(const string& nom_, const string& departement_, float salaire_);
    virtual ~Employe(){};

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
    Personne equipe[5]; // un tableau natif avec une taille statique.
    equipe[0] = Personne("marc");
    equipe[1] = Etudiant("marie", "medecine", 4.1f);
    equipe[2] = Etudiant("jean", "informatique", 3.5);
    equipe[3] = Employe("robert", "finances", 62400);
    equipe[4] = Employe("anne", "ingenerie", 67400);

    for(int i=0;i<5;i++){
        cout << "[" << i << "] ";
        equipe[i].afficher();
    }

    return 0;
}

