#pragma once
#include "../abstract/Quartier.h"
#include <vector>

class Temple : public Quartier {
public:
    Temple(int id, bool v);
    Temple(const Temple& q);
    Temple& operator=(const Temple& q);
    bool est_valide(std::vector<Construction*>& voisins);
    bool variante_hauteur(int etage);
};