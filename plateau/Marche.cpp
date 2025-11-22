#include "Marche.h"
#include "Place.h"
#include <vector>

Marche::Marche(int id, bool v) : Quartier(id, v) {}

//Marche::Marche(const Marche& q) : Quartier(q) {}

/*Marche& Marche::operator=(const Marche& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}*/

bool Marche::est_valide(std::vector<Construction*>& voisins) {
    for (Construction* voisin : voisins) {
        if (voisin->get_type_construction() == "Marche") {
            return false; 
        }
    }
    return true; 
}
bool Marche::variante_place(std::vector<Construction*>& voisins) {
    for (Construction* voisin : voisins) {
        if (voisin != nullptr) {
            Place* p = dynamic_cast<Place*>(voisin);
            if (p != nullptr && p->getCouleur() == "Rouge") {
                return true; 
            }
        }
    }
    return false;
}
std::string Marche::get_type_construction() const {
    return "Marche";
}