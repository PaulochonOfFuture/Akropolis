#pragma once
#include "../abstract/Quartier.h"
#include <vector>

class Temple : public Quartier {
public:
    Temple(int id, bool v);
    //Temple(const Temple& q);
    //Temple& operator=(const Temple& q);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Construction*>& voisins) override;
    bool variante_hauteur(int etage);
};