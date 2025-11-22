#include "Habitation.h"
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
bool Habitation::habitation_voisine(std::vector<Construction*>& voisins) const {
    for (Construction* voisin : voisins) {
        if (voisin->get_type_construction() == "Habitation") {
            return true; 
        }
    }
    return false; 
}
std::string Habitation::get_type_construction() const {
    return "Habitation";
}