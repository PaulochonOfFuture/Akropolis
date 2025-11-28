#include "Temple.h"
#include "Hexagone.h"
#include <vector>

Temple::Temple(int id, bool v) : Quartier(id, v) {}

//Temple::Temple(const Temple& q) : Quartier(q) {}

/*Temple& Temple::operator=(const Temple& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}*/

bool Temple::est_valide(std::vector<Hexagone*>& voisins) {
    for (Hexagone* h : voisins) {
        if (h == nullptr || h->get_est_vide()) {
            return false;
        }
    }
    return true;
}
bool Temple::variante_hauteur(int etage) {
    return (etage >= 1);
}
std::string Temple::get_type_construction() const {
    return "Temple";
}
