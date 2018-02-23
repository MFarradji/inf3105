/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 7 : utilisation d'un std::vector

   etape3.cpp à etape6.cpp
    --> Nous avons utilisé des tableaux (arrays) 'natifs' de C/C++.
    --> C'est limité, car ils ont une taille fixe.

   etape.cpp
    --> Nous pouvons utiliser la classe générique std::vector<>
        qui permet un redimentionnement automatique.
    --> Cela est équivalent à la classe Tableau<> dans la section 4
        des notes de cours.
*/


#include <iostream>
#include <vector> // Ligne ajoutée
using namespace std;

class Personne{
  public:
    Personne(const string& nom="?"); // ou mettre une valeur par défaut ici afin de créer un objet Personne sans argument

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

int main()
{
    // vecteur créé sur la pile
    // comme ma classe Tableau<>, un vector<> contient un pointeur vers un tableau natif
    // mais, c'est transparent pour nous...
    vector<Personne*> equipe;

    equipe.push_back(new Personne("marc"));
    equipe.push_back(new Etudiant("marie", "medecine", 4.1f));
    equipe.push_back(new Etudiant("sophie", "informatique", 3.5));
    equipe.push_back(new Employe("robert", "finances", 62400));
    equipe.push_back(new Employe("anne", "ingenerie", 67400));

    for(int i=0;i<equipe.size();i++){
        cout << "[" << i << "] ";
        equipe[i]->afficher();
    }

    for(int i=0;i<equipe.size();i++)
        delete equipe[i];

    // vector<Personne*> est sur la pile, nous n'avons pas besoin de le libérer
    // Le compilateur le fera tout seul
    // Le destructeur vector<>::~vector() libère lui-même son tableau natif comme Tableau<>

    return 0;
}

