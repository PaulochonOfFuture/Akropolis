#include "ChaineHabitation.h"

// Opérateur += (ajout d'une chaine)
Chaine_habitation& Chaine_habitation::operator+=(const Chaine_habitation& c2) {
    for (Habitation* h : c2.habitations) {
        habitations.push_back(h);
        h->setChaineMere(id_chaine);
    }

    longueur += c2.longueur;

    return *this;
}

// Opérateur += (ajout d'une habitation)
Chaine_habitation& Chaine_habitation::operator+=(Habitation* h) {
    habitations.push_back(h);
    longueur++; //pas bon, une habitation peut etre a un etage

    h->setChaineMere(id_chaine);

    return *this;
}

    // Comparaison (relation d'ordre)
bool Chaine_habitation::operator>(const Chaine_habitation& c2) const {
    return longueur > c2.longueur;
}

bool Chaine_habitation::operator>(int l) const {
    return longueur > l;
}