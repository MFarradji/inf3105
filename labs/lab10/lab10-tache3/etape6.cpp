/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 6 : l'héritage et les tableaux dynamiques

   etape5.cpp
    --> Équipe avait une taille fixe.

   etape6.cpp
    --> Examinons le cas avec un tableau dynamique.
*/


#include <iostream>
using namespace std;

class Personne{
  public:
    Personne(const string& nom="?");

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
   //Personne(nom) : comme Etudiant dérive de Personne, il faut construire la partie Personne
   //                on appelle donc le constructeur Personne(const string&)
 {
 }

void Etudiant::afficher() const{
    cout << "Etudiant: nom=" << nom << ", programme=" << programme << ", moyenne=" << moyenne << "/4.3" << std::endl;
}



Employe::Employe(const string& nom_, const string& departement_, float salaire_)
 : Personne(nom_), departement(departement_), salaire(salaire_)
   //Personne(nom) : comme Employe dérive de Personne, il faut construire la partie Personne
   //                on appelle donc le constructeur Personne(const string&)
 {
 }

void Employe::afficher() const{
    cout << "Employe: nom=" << nom << ", departement=" << departement << ", salaire=" << salaire << "$/an" << std::endl;
}

//***** Fin des définitions *************/

int main()
{
    Personne** equipe = new Personne*[5]; // tableau créé dynamiquement
    equipe[0] = new Personne("marc");
    equipe[1] = new Etudiant("marie", "medecine", 4.1f);
    equipe[2] = new Etudiant("sophie", "informatique", 3.5);
    equipe[3] = new Employe("robert", "finances", 62400);
    equipe[4] = new Employe("anne", "ingenerie", 67400);

    for(int i=0;i<5;i++){
        cout << "[" << i << "] ";
        equipe[i]->afficher();
    }

    // Libération de la mémoire
    // C'est maintenant un peu plus compliqué
    // On ne peut pas seulement faire 'delete []equipe' car cela libère le tableau de pointeurs
    // mais laisse les 5 objets créés

    for(int i=0;i<5;i++)
        delete equipe[i]; // l'objet pointé par equipe[i] n'est pas un tableau, donc il ne faut pas faire delete[] equipe[i];

    // Il faut aussi libérer la mémoire de equipe, car ce tableau n'est plus créé sur la pile, mais sur le heap
    // et il faut le faire après avec les delete sur les objets
    delete[] equipe;

    return 0;
}

