#pragma once
#include <vector>
#include "Joueur.h"
#include "../plateau/Coordonnee.h"
#include "../plateau/Chantier.h"

class Partie {
private:
    int nb_joueurs;
    bool courante;
    bool variantes[5];
    Joueur* joueurs;   
    Coordonnee* coordonnees;
    Chantier* chantiers;
public:
    bool setCourante();
    int getNbJoueurs() const;
    std::vector<Joueur&> determiner_classement();
    Partie(int j, bool c, bool[5], std::vector<std::string> noms);
};
