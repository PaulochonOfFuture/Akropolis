#pragma once
#include "Habitation.h"

class Chaine_habitation {
private:
    std::vector<Habitation&> habitations; 
    int id_chaine;
    int longueur;
public:
    Chaine_habitation& opereator+=(Chaine_habitation&);
    Chaine_habitation& opereator+=(Habitation&);
    bool opereator>(Chaine_habitation&);
    Chaine_habitation(int, int);
};
