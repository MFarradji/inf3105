/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 5 : l'héritage et les tableaux statiques.

   Problème?
    --> Les objets stockés sont des objets de type Personne.
    --> Les objets Etudiant et Employe sont temporairement créés sur la pile, MAIS
        seule la partie du type Personne est copiée dans le tableau.

   Solution:
    --> Nous n'avons pas le choix, nous devons créer un tableau de pointeurs vers des objets
        et NON un tableau d'objets.
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
{
}

void Employe::afficher() const{
    cout << "Employe: nom=" << nom << ", departement=" << departement << ", salaire=" << salaire << "$/an" << std::endl;
}

//***** Fin des définitions *************/

int main(){
    Personne* equipe[5]; // Tableau de pointeurs.
    equipe[0] = new Personne("marc");
    equipe[1] = new Etudiant("marie", "medecine", 4.1f);
    equipe[2] = new Etudiant("sophie", "informatique", 3.5);
    equipe[3] = new Employe("robert", "finances", 62400);
    equipe[4] = new Employe("anne", "ingenerie", 67400);

    for(int i=0;i<5;i++){
        cout << "[" << i << "] ";
        equipe[i]->afficher();
    }

    // Libération de la mémoire.
    // C'est maintenant un peu plus compliqué.
    // On ne peut pas seulement faire 'delete [] equipe' car cela ne libère que le tableau de pointeurs,
    // mais laisse en mémoire les 5 objets créés avec les new.

    for(int i=0;i<5;i++)
        delete equipe[i]; // L'objet pointé par equipe[i] n'est pas un tableau, donc il ne faut pas faire delete[] equipe[i].
                          // Certains peuvent recommander d'ajouter delete [], mais c'est une erreur.

    return 0;
}

