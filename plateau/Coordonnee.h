#pragma once
#include <vector>

class Coordonnee {
private:
    int x;
    int y;
public:
    std::vector<Coordonnee> get_coord_voisine(); 
    bool operator>(const Coordonnee&) const;
};