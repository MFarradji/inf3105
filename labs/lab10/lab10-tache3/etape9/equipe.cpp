/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 9 : séparation du code en plusieurs fichiers.
*/

#include "equipe.h"
#include <iostream>

Equipe::Equipe(const string& nomequipe_)
 : nomequipe(nomequipe_)
{
   // Le vecteur est un objet à part entière. Il se crée donc tout seul
}

Equipe::~Equipe()
{
    // Les membres ont été alloués à quelque part... il faut les libérer à quelque part, comme ici.
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


