#pragma once
#include "../abstract/Quartier.h"
#include <vector>

class Caserne : public Quartier {
public:
    Caserne(int id, bool v);
    Caserne(const Caserne& q);
    Caserne& operator=(const Caserne& q);
    bool est_valide(std::vector<Construction*>& voisins);
    bool est_libre_3(std::vector<Construction*>& voisins);
};