#pragma once
#include <vector>
#include "Habitation.h"

class Chaine_habitation {
private:
    std::vector<Habitation*> habitations; 
    int id_chaine;
    int longueur;
public:
    Chaine_habitation& operator+=(Chaine_habitation& c);
    Chaine_habitation& operator+=(Habitation& h);
    bool operator>(Chaine_habitation& c);
    Chaine_habitation(int id, int l);
};
