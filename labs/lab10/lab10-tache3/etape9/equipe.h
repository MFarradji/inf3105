/*
   INF3105 / Lab10 -- Exercices sur l'héritage et les conteneurs.

   Étape 9 : séparation du code en plusieurs fichiers.
*/

#if !defined(__EQUIPE_H__)
#define __EQUIPE_H__

#include "personne.h"
#include <vector>

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



#endif

