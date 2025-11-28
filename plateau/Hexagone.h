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
    void set_constru(Construction& c) { construction = &c; }
    Construction* get_constru() const { return construction; }
    int get_etage() const { return etage; }
    bool get_est_vide() const {return est_vide;}
};

