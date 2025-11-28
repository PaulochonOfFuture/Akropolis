#include "Marche.h"
#include "Place.h"
#include "Hexagone.h"
#include <vector>

Marche::Marche(int id, bool v) : Quartier(id, v) {}

//Marche::Marche(const Marche& q) : Quartier(q) {}

/*Marche& Marche::operator=(const Marche& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}*/

bool Marche::est_valide(std::vector<Hexagone*>& voisins) {
    for (Hexagone* voisin : voisins) {
        if (voisin != nullptr && !voisin->get_est_vide()) {
            Construction* c = voisin->get_constru();
            if (c != nullptr && c->get_type_construction() == "Marche") {
                return false;
            }
        }
    }
    return true;
}
bool Marche::variante_place(std::vector<Hexagone*>& voisins) {
    for (Hexagone* h : voisins) {
        if (h != nullptr && !h->get_est_vide()) {
            Construction* c = h->get_constru();
            Place* p = dynamic_cast<Place*>(c);
            if (p != nullptr && p->getCouleur() == "Jaune") {
                return true;
            }
        }
    }
    return false;
}
std::string Marche::get_type_construction() const {
    return "Marche";
}