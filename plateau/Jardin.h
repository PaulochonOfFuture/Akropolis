#pragma once
#include "../abstract/Quartier.h"
#include"Hexagone.h"
#include <vector>

class Jardin : public Quartier {
public:
    Jardin(int id, bool v);
    //Jardin(const Jardin& q);
    //Jardin& operator=(const Jardin& q);
    bool lac(std::vector<Hexagone*>& voisins);
    std::string get_type_construction() const override;
    bool est_valide(std::vector<Hexagone*>& voisins) override;

};