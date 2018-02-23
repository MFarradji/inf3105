/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 9 : séparation du code en plusieurs fichiers.
*/

#include <iostream>
#include "equipe.h"

int main(){
    Equipe equipe("Expos");
    equipe.ajouter(new Personne("marc"));
    equipe.ajouter(new Etudiant("marie", "medecine", 4.1f));
    equipe.ajouter(new Etudiant("sophie", "informatique", 3.5));
    equipe.ajouter(new Employe("robert", "finances", 62400));
    equipe.ajouter(new Employe("anne", "ingenerie", 67400));
    equipe.afficher();
    return 0;
}

