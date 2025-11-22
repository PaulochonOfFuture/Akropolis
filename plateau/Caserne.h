#pragma once
#include "../abstract/Quartier.h"
#include <vector>

class Caserne : public Quartier {
public:
    Caserne(int id, bool v);
    //Caserne(const Caserne& q);
    //Caserne& operator=(const Caserne& q);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Construction*>& voisins) override;
    bool est_libre_3(std::vector<Construction*>& voisins);
};