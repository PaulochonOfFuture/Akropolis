#include "Habitation.h"
#include "Hexagone.h"
#include <vector>


Habitation::Habitation(int id, bool v) : Quartier(id, v) {
    this->id_chaine_mere = 0 ;
}

/*Habitation::Habitation(const Habitation& q) : Quartier(q) {
    this->id_chaine_mere = q.id_chaine_mere;
}

Habitation& Habitation::operator=(const Habitation& q) {
    if (this != &q) {
        Quartier::operator=(q);
        this->id_chaine_mere = q.id_chaine_mere;
    }
    return *this;
}*/

bool Habitation::est_valide(std::vector<Hexagone*>& voisins) {
    return true;
}

bool Habitation::habitation_voisine(std::vector<Hexagone*>& voisins) const {
    for (Hexagone* voisin : voisins) {
        if (voisin != nullptr && !voisin->get_est_vide()) {
            Construction* c = voisin->get_constru();
            if (c != nullptr && c->get_type_construction() == "Habitation") {
                return true;
            }
        }
    }
    return false;
}
std::string Habitation::get_type_construction() const {
    return "Habitation";
}