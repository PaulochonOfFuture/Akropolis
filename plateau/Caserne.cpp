#include "Caserne.h"
#include "Hexagone.h"
#include <vector>

Caserne::Caserne(int id, bool v) : Quartier(id, v) {}

//Caserne::Caserne(const Caserne& q) : Quartier(q) {}

/*Caserne& Caserne::operator=(const Caserne& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}*/

bool Caserne::est_valide(std::vector<Hexagone*>& voisins) {
    for (Hexagone* h : voisins) {
        if (h == nullptr || h->get_est_vide()) return true;
    }
    return false;
}

bool Caserne::est_libre_3(std::vector<Hexagone*>& voisins) {
    int libres = 0;
    for (Hexagone* h : voisins) {
        if (h == nullptr || h->get_est_vide()) libres++;
    }
    return (libres >= 3);
}
std::string Caserne::get_type_construction() const {
    return "Caserne";
}