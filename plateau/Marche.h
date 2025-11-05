#pragma once
#include "Quartier.h"
#include <vector>
class Marche : public Quartier {
public:
    Marche(int id, bool v);
    Marche(const Marche& q);
    Marche& operator=(const Marche& q);
    bool est_valide(std::vector<Construction*>& voisins);
};
