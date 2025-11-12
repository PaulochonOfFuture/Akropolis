#include "Habitation.h"
#include <vector>


Habitation::Habitation(int id, bool v) : Quartier(id, v) {
    this->id_chaine_mere = 0 ;
}

Habitation::Habitation(int id, bool v) : Quartier(id, v) {
    this->id_chaine_mere = /* ? ? ? ?*/ ;
}


Habitation::Habitation(const Habitation& q) : Quartier(q) {
    this->id_chaine_mere = q.id_chaine_mere;
}

Habitation& Habitation::operator=(const Habitation& q) {
    if (this != &q) {
        Quartier::operator=(q);
        this->id_chaine_mere = q.id_chaine_mere;
    }
    return *this;
}

/* je pense dans .h  on doit avoir bool habitation_voisine(std::vector<Construction>& voisins) const et dans UML aussi */
/* il manque Habitation& operator= dans UML */
/* il manque pas in geteur */
/*il y a une remarque sur est valide dans UML or cette methode n'existe pas */
