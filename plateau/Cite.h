#pragma once
#include "Hexagone.h"
#include "Tuile.h"
#include <vector>

class Cite {
private:
    int chaine_habitation;
    std::vector<Hexagone> carte; /*a revoir le vecteur*/
    Tuile* tuile_temporaire;
    Coordonnee position_temporaire; 

public:
    void afficher_cite();
    Hexagone* recherche_hexagone(Coordonnee);
    void maj_cite(Tuile*, Coordonnee&);
    void set_tuile_temporaire(Tuile*);
    void set_position_temporaire(Coordonnee&);
    const std::vector<Construction&> get_voisins(Coordonnee&); /*a revoir le vecteur*/
        
};
