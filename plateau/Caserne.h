#pragma once
#include "../abstract/Quartier.h"
#include <vector>
#include"Hexagone.h"

class Caserne : public Quartier {
public:
    Caserne(int id, bool v);
    //Caserne(const Caserne& q);
    //Caserne& operator=(const Caserne& q);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Hexagone*>& voisins) override;
    bool est_libre_3(std::vector<Hexagone*>& voisins);
};