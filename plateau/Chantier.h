#pragma once
#include "Tuile.h"
#include <vector>

class Chantier {
private:
    int taille_max;
    std::vector<Tuile> pioche;
    int indice_début;
public:
    const int calculer_cout(int i);
    const void afficher_chantier();
    void maj_chantier();
    Chantier(int max);
    ~Chantier() = default;

};