#pragma once
#include "../abstract/Quartier.h"
#include <vector>
#include"Hexagone.h"
class Marche : public Quartier {
public:
    Marche(int id, bool v);
    //Marche(const Marche& q);
    //Marche& operator=(const Marche& q);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Hexagone*>& voisins) override;
    bool variante_place(std::vector<Hexagone*>& voisins);
};
