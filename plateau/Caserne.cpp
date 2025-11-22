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

bool Caserne::est_valide(std::vector<Construction*>& voisins) {
    for (Construction* c : voisins) {
        if (c == nullptr) return true; 
    }
    return false;
}

bool Caserne::est_libre_3(std::vector<Construction*>& voisins) {
    int libres = 0;
    for (Construction* c : voisins) {
        if (c == nullptr) libres++;
    }
    return (libres >= 3);
}