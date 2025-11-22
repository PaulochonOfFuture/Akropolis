#include "Quartier.h"
Quartier::Quartier(int i, bool v) : Construction(i), valide(v) {
}

//Quartier::Quartier(const Quartier& q) : Construction(q), valide(q.valide) {}

/*Quartier& Quartier::operator=(const Quartier& q) {
    if (this != &q) {
        Construction::operator=(q);
        this->valide = q.valide;
    }
    return *this;
}*/