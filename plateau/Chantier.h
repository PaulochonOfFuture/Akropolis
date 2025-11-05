#pragma once
#include "Tuile.h"
#include <vector>

class Chantier {
private:
    int taille_max;
    std::vector<Tuile> pioche;
    int indice_début;
public:
    const int calculer_cout(int);
    void afficher_chantier();
    void maj_chantier();
    Chantier(int);
    ~Chantier(int);

};