#pragma once
#include "../abstract/Construction.h"
#include "Coordonnee.h"  

class Hexagone {
private:
    Construction* construction; 
    Coordonnee* coordonnee;
    int étage;
    bool est_vide;
 public:
    std::vector<Construction&> get_voisin();
    void afficher_hexagone();
};