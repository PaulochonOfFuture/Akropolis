#pragma once
#include <vector>
#include <iostream>
#include "Tuile.h" 

class Chantier {
private:
    int taille_max;
    std::vector<Tuile*> pioche;
    int indice_debut;
    Chantier() = default;
public:
    Chantier(int max);
    ~Chantier();
    int calculer_cout(int i) const;
    void afficher_chantier() const;
    void maj_chantier();
    Tuile* get_tuile(int rang);
    bool est_vide() const;
    int get_taille() const { return taille_max; }
};