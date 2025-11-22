#pragma once
#include "../abstract/Quartier.h"
#include <vector>
class Marche : public Quartier {
public:
    Marche(int id, bool v);
    //Marche(const Marche& q);
    //Marche& operator=(const Marche& q);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Construction*>& voisins) override;
    bool variante_place(std::vector<Construction*>& voisins);
};
