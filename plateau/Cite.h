#pragma once
#include "Hexagone.h"
#include "Tuile.h"
#include "Coordonnee.h"
#include <vector>

class Cite {
private:
    int chaine_habitation;
    std::vector<Hexagone> carte;
    Tuile* tuile_temporaire;
    Coordonnee position_temporaire; 

public:
    void afficher_cite();
    Hexagone* recherche_hexagone(Coordonnee);
    void maj_cite(Tuile* tuile, Coordonnee& c);
    void set_tuile_temporaire(Tuile* t);
    void set_position_temporaire(Coordonnee& t);
    const std::vector<Hexagone> get_voisins(Coordonnee& c); 
        
};
