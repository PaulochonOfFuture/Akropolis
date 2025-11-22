#include "Jardin.h"
#include <vector>

Jardin::Jardin(int id, bool v) : Quartier(id, v) {}

Jardin::Jardin(const Jardin& q) : Quartier(q) {}

Jardin& Jardin::operator=(const Jardin& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}

bool Jardin::est_valide(std::vector<Construction*>& voisins) {
    return true;
}

