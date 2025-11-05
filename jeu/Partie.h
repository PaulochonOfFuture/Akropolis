#pragma once
#include <vector>
#include "Joueur.h"
#include "Coordonnee.h"
#include "Chantier.h"

class Partie {
private:
    int nb_joueurs;
    bool courante;
    bool variantes;
    Joueur* joueurs;   
    Coordonnee* coordonnees;
    Chantier* chantiers;
public:
    bool setCourante();
    int getNbJoueurs() const;
    void initialiser_partie();
    void determiner_classement();
    void fin_chantier();
};
