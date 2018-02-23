/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 8 : Classe Équipe.
*/

#include <iostream>
#include <vector> // Ligne ajoutée
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

class Equipe {
  public:
    Equipe(const string& nomequipe_="equipesansnom");
    ~Equipe(); // un destructeur est requis
    void ajouter(Personne* p);
    void afficher() const;

  protected:
    string nomequipe;
    vector<Personne*> membres;
};

//***** Début des définitions (implémentations des constructeurs et fonctions) *************/
// Ceci irait normalement dans un ou des fichiers .cpp (ou .cc, .c++)

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

Equipe::Equipe(const string& nomequipe_)
 : nomequipe(nomequipe_)
{
   // Le vecteur est un objet à part entière. Il se crée donc tout seul. Pas besoin de faire quelque chose de particulier.
}

Equipe::~Equipe()
{
    // les membres ont été alloués à quelque part... il faut les libérer à quelque part, comme ici
    for(int i=0;i<membres.size();i++)
        delete membres[i];
}

void Equipe::ajouter(Personne* p){
    // On ne fait que copier le pointeur et non l'objet
    // l'objet Personne reste au même endroit et ne bouge pas.
    membres.push_back(p);
}

void Equipe::afficher() const
{
    cout << "Équipe : " << nomequipe << endl;
    for(int i=0;i<membres.size();i++){
        cout << "  [" << i << "] ";
        membres[i]->afficher();
    }
}
//***** Fin des définitions *************/

int main()
{
    Equipe equipe("Expos");
    equipe.ajouter(new Personne("marc"));
    equipe.ajouter(new Etudiant("marie", "medecine", 4.1f));
    equipe.ajouter(new Etudiant("sophie", "informatique", 3.5));
    equipe.ajouter(new Employe("robert", "finances", 62400));
    equipe.ajouter(new Employe("anne", "ingenerie", 67400));
    equipe.afficher();

    // La mémoire se libérera correctement, car les objets alloués par les new sont libérés dans le destructeur Equipe::~Equipe().
    return 0;
}

