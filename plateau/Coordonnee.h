#pragma once
#include <vector>
#include <array>

class Coordonnee {
private:
    int x;
    int y;

public:
    Coordonnee(int x_, int y_) : x(x_), y(y_) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // On crée une relation d'ordre pour qu'une Coordonée puisse être utilisé comme clé dans la map de Cité (ARN):
    bool operator<(const Coordonnee& other) const {
        if (x < other.x) return true;
        if (x > other.x) return false;
        return y < other.y;
    }

    // Les 6 coordonées voisines :
    std::array<Coordonnee, 6> get_voisines() const;
};