#pragma once
#include "Quartier.h"
#include <vector>

class Jardin : public Quartier {
public:
    Jardin(int id, bool v);
    Jardin(const Jardin& q);

    Jardin& operator=(const Jardin& q);

    bool est_valide(std::vector<Construction*>& voisins);
    bool lac(std::vector<Construction*>& voisins);

};