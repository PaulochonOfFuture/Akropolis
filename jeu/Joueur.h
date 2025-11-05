#pragma once
#include "../plateau/Cite.h"
#include <string>

class Joueur {
private:
    Cite* cite;
    int score;
    int nb_pierres;
    std::string nom;
    const int id_joueur;
public:
    void maj_score();
    void ajouter_tuile(); /*voir le type*/
    void debiter_pierres();
    void ajouter_pierres();
    int get_nb_pierres();
    void set_score(int);
    int get_score();
    Tuile* choisir_tuile(int rang);
    void placer_tuiles_temporairement(Coordonnee c1, Coordonnee c2, Coordonnee c3, Tuile* t);
    void tourner_tuile_temporaire();
    void confirmer_emplacement();
};
