#include "Caserne.h"
#include <vector>

Caserne::Caserne(int id, bool v) : Quartier(id, v) {}

Caserne::Caserne(const Caserne& q) : Quartier(q) {}

Caserne& Caserne::operator=(const Caserne& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}

bool Caserne::est_valide(std::vector<Construction>& voisins) {
    if (voisins.size() < 6) {
        return true;
    }
    return false; 
}

bool Caserne::est_libre_3(std::vector<Construction>& voisins) {
    if (voisins.size() <= 3) {
        return true;
    }
    return false;
}