#include "Coordonnee.h"


std::array<Coordonnee, 6> Coordonnee::get_voisines() const {
   return {
        Coordonnee{x + 1, y    },
        Coordonnee{x + 1, y + 1},
        Coordonnee{x    , y + 1},
        Coordonnee{x - 1, y    },
        Coordonnee{x - 1, y - 1},
        Coordonnee{x    , y - 1}
    };
}