#include "Jardin.h"
#include <vector>

Jardin::Jardin(int id, bool v) : Quartier(id, v) {}

Jardin::Jardin(const Jardin& q) : Quartier(q) {}

Jardin& Jardin::operator=(const Jardin& q) {
    if (this != &q) {
        Quartier::operator=(q);
    }
    return *this;
}

bool Jardin::est_valide(std::vector<Construction>& voisins) {
    return true;
}

/*est valide ca sert a rien dans jardin*/
/*on ne peut pas faire la methode lac car on n'a pas besoin que des voisin il faut le plateau ou la cité */