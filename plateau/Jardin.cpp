#include "Jardin.h"
#include "Hexagone.h"
#include <vector>

Jardin::Jardin(int id, bool v) : Quartier(id, v) {}

//Jardin::Jardin(const Jardin& q) : Quartier(q) {}

/*Jardin& Jardin::operator=(const Jardin& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}*/

bool Jardin::est_valide(std::vector<Hexagone*>& voisins) {
    return true;
}
bool Jardin::lac(std::vector<Hexagone*>& voisins) {
    for (Hexagone* hex : voisins) {
        if (hex == nullptr) {
            // C'est un pointeur nul, donc c'est la fin du plateau.Ce n'est PAS un lac
            continue;
        }
        if (hex->get_est_vide()) {
            // C'est un Hexagone qui existe mais qui n'a pas de construction.C'est donc un Lac adjacent !
            return true;
        }
    }
    return false;
}
std::string Jardin::get_type_construction() const {
    return "Jardin";
}

