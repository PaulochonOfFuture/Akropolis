#include "Temple.h"
#include <vector>

Temple::Temple(int id, bool v) : Quartier(id, v) {}

Temple::Temple(const Temple& q) : Quartier(q) {}

Temple& Temple::operator=(const Temple& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}

bool Temple::est_valide(std::vector<Construction>& voisins) {
    if (voisins.size() < 6) {
        return false;
    }
    return true; 
}
