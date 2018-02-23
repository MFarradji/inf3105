/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 2 : Comprendre le mécanisme des fonctions virtuelles.

   - Le problème à la fin de etape1.cpp est que p2->afficher() appelle la
     fonction Personne::afficher() au lieu de Etudiant::afficher().
   - Ceci est normal puisque le compilateur ne sait pas que p2 est un pointeur
     vers un objet Etudiant. Dans cet exemple, cela semble évident que p2 est
     un étudiant, mais il est parfois impossible de déduire au moment de la
     compilation.
   - Pour régler ce problème, il faut en quelque sorte attacher le type de
     l'objet sur chaque objet. Ainsi, si on sait que p2 est un pointeur vers un
     objet Etudiant, on peut appeler la bonne fonction, soit Etudiant::afficher().
   - Une façon de procéder est l'ajout du mot clé virtual devant les fonctions.
   - Une fonction est virtuelle au sens qu'on fait abstraction de quelle
     est la véritable fonction qui est appelée.
   - Donc, ajoutons virtual devant la fonction afficher() dans la classe Personne.
*/

#include <iostream>
using namespace std;


class Personne{
  public:
    Personne(const string& nom);
    virtual void afficher() const;
  protected:
    string nom;
};


class Etudiant : public Personne{
  public:
    Etudiant(const string& nom_, const string& programme_, float moyenne_);
    virtual void afficher() const;
    // comme Personne::afficher() est virtual, Etudiant::afficher() l'est automatiquement.
    // même si le mot clé virtual n'était pas là.
  protected:
    string programme;
    float moyenne;
};

class Employe : public Personne{
  public:
    Employe(const string& nom_, const string& departement_, float salaire_);
    void afficher() const;
    // comme Personne::afficher() est virtual, Employe::afficher() l'est aussi, même sans ajouter le mot clé virtual.
  protected:
    string departement;
    float salaire;
};
//***** Fin des déclarations *************/

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

//***** Le programme principal *************/
int main(){
    Personne p1("jean");
    p1.afficher();

    Etudiant et1("marie", "medecine", 4.1f);
    et1.afficher();

    Employe ep1("robert", "finances", 62400);
    ep1.afficher();
    // Jusqu'ici, c'est assez simple

    // Que font les 2 lignes suivantes?
    Personne p2 = et1;
    p2.afficher();
    // Indice : p2 est un objet Personne. La partie Personne de l'objet et1 a été copiée dans p2


    // Que font les 2 lignes suivantes?
    Personne* p3 = &et1;
    p3->afficher();
    // Le problème est-il réglé?

    // Que font les 2 lignes suivantes?
    Personne* p4 = &ep1;
    p4->afficher();
    // Le problème est-il réglé?

    return 0;
}
