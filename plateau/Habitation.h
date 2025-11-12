#pragma once
#include "../abstract/Quartier.h"
#include <vector>

class Habitation : public Quartier {
private:
    int id_chaine_mere;
public:
 
    Habitation(int id, bool v);
    Habitation(const Habitation& q);
    Habitation& operator=(const Habitation& q);
    bool habitation_voisine(std::vector<Construction*>& voisins) const;
};