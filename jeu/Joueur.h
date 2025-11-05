#pragma once
#include "Cite.h"
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
    Tuile* choisir_tuile(int); /*faut pas un include tuile?*/
    void placer_tuiles_temporairement(Coordonée, Coordonée, Coordonée, Tuile*); /*et coordoné*/
    void tourner_tuile_temporaire();
    void confirmer_emplacement();
};
