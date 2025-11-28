#include "Coordonnee.h"

// Renvoi les 6 coordonnées voisines :
std::vector<Coordonnee> Coordonnee::get_voisines() const {
    return {
        Coordonnee{x + 1, y    },
        Coordonnee{x + 1, y + 1},
        Coordonnee{x    , y + 1},
        Coordonnee{x - 1, y    },
        Coordonnee{x - 1, y - 1},
        Coordonnee{x    , y - 1}
    };
}

// Vérifie si une autre coordonnée est sa voisine :
bool Coordonnee::est_voisine(const Coordonnee& c) const
{
    int dx = c.getX() - x;
    int dy = c.getY() - y;

    return
        (dx ==  1 && dy ==  0) ||
        (dx ==  1 && dy ==  1) ||
        (dx ==  0 && dy ==  1) ||
        (dx == -1 && dy ==  0) ||
        (dx == -1 && dy == -1) ||
        (dx ==  0 && dy == -1);
}

// Vérifie si 3 coordonnées sont des voisines :
bool trio_coordonnees_voisines(const Coordonnee& c1, const Coordonnee& c2, const Coordonnee& c3){
    return
        c1.est_voisine(c2) && c1.est_voisine(c3) &&
        c2.est_voisine(c1) && c2.est_voisine(c3) &&
        c3.est_voisine(c1) && c3.est_voisine(c2);
}
