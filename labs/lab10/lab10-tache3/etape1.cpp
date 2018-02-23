/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 1 : Comprendre le mécanisme d'héritage.
*/

#include <iostream>
using namespace std;

//***** Début des déclarations *************/
// Ceci irait normalement dans un ou plusieurs fichiers .h (personne.h, etudiant.h, employe.h).
// En C++, une telle séparation est facultative, bien qu'elle puisse faciliter l'organisation d'un projet.
// Nous le ferons plus tard (etape9). Pour l'instant, nous mettons tout dans un seul
// fichier afin de minimiser le nombre de fichiers à visualiser pour chaque étape.

// Déclaration d'une classe de base Personne.
class Personne{
  public:
    Personne(const string& nom);

    void afficher() const;

  protected: // Le modificateur d'accès 'protected' est plus souple que 'private'.
             // Si 'nom' était private, les sous-classes n'auraient pas accès à 'nom'.
             // Pour y accéder, il faudrait ajouter des setNom() et getNom();
             // En le mettant protected, on permet aux fonctions des sous-classes d'y
             // avoir directement accès.
    string nom;
};

// Déclaration d'une classe Etudiant héritant de Personne.
// "un Etudiant est une Personne"
// "une Personne n'est pas nécessairement un Etudiant"
class Etudiant : public Personne{
  public:
    Etudiant(const string& nom_, const string& programme_, float moyenne_);

    void afficher() const;

  protected:
    string programme;
    float moyenne;
};

// Déclaration d'une classe Employe héritant de Personne.
// "un Employe est une Personne"
// "une Personne n'est pas nécessairement un Employe"
class Employe : public Personne{
  public:
    Employe(const string& nom_, const string& departement_, float salaire_);

    void afficher() const;

  protected:
    string departement;
    float salaire;
};

//***** Fin des déclarations *************/

//***** Début des définitions (implémentations des constructeurs et fonctions) *************/
// Ceci irait normalement dans un ou des fichiers .cpp (ou .cc, .c++)

Personne::Personne(const string& nom_)
 : nom(nom_)  // après le «:» , la partie initialisation.
  // nom(nom_) signifie qu'on construit nom par copie de nom_
 {

 }

void Personne::afficher() const{
    cout << "Personne: nom=" << nom << std::endl;
}

Etudiant::Etudiant(const string& nom_, const string& programme_, float moyenne_)
 : Personne(nom_), programme(programme_), moyenne(moyenne_)
   //Personne(nom) : comme Etudiant dérive de Personne, il faut construire la partie Personne,
   //                donc, on appelle le constructeur Personne(const string&).
{
}

void Etudiant::afficher() const{
    cout << "Etudiant: nom=" << nom << ", programme=" << programme << ", moyenne=" << moyenne << "/4.3" << std::endl;
}



Employe::Employe(const string& nom_, const string& departement_, float salaire_)
 : Personne(nom_), departement(departement_), salaire(salaire_)
   //Personne(nom) : comme Employe dérive de Personne, il faut construire la partie Personne,
   //                donc, on appelle le constructeur Personne(const string&).
{
}

void Employe::afficher() const{
    cout << "Employe: nom=" << nom << ", departement=" << departement << ", salaire=" << salaire << "$/an" << std::endl;
}

//***** Fin des définitions *************/

//***** Le programme principal *************/

int main(){
    Personne p1("jean");
    p1.afficher();

    Etudiant et1("marie", "medecine", 4.1f);
    et1.afficher();

    Employe ep1("robert", "finances", 62400);
    ep1.afficher();
    // Jusqu'ici, c'est assez simple.

    // Que font les 2 lignes suivantes?
    Personne p2 = et1;
    p2.afficher();
    // Indice : p2 est un objet Personne. La partie Personne de l'objet et1 a été copiée dans p2.

    // Que font les 2 lignes suivantes?
    Personne* p3 = &et1;
    p3->afficher();
    // Indice : p3 est un pointeur vers une Personne.
    // p3 pointe bien vers l'objet et1.
    // Toutefois, c'est la fonction Personne::afficher() qui est appelée.
    // Nous corrigerons cela dans etape2.cpp.
    return 0;
}
