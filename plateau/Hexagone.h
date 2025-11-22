#pragma once
#include "../abstract/Construction.h"


class Hexagone {
private:
    Construction* construction;
    int etage;
    bool est_vide;

public:
    Hexagone() : construction(nullptr), etage(0), est_vide(true) {}

    void afficher_hexagone() const;
};