#pragma once
#include <string>
#include <iostream>
#include "Cite.h"      
#include "Chantier.h"  
#include "Coordonnee.h"

class Joueur {
private:
    const int id_joueur;
    const std::string nom;
    int nb_pierres;
    int score;
    Cite* cite;

public:
    Joueur(int id, std::string n);
    ~Joueur();
    void maj_score();
    void ajouter_tuile();
    void debiter_pierres(int i);
    void ajouter_pierres(int i);
    int get_nb_pierres() const;
    void set_score(int s);
    int get_score() const;
    Cite* get_Cite() const;
    std::string getNom() const { return nom; }
    void afficher_cite() const;
    bool choisir_tuile(int rang, Chantier& chantier);
    void placer_tuiles_temporairement(Coordonnee c1, Coordonnee c2, Coordonnee c3, Tuile* t);
    void tourner_tuile_temporaire();
    void confirmer_emplacement(Chantier& chantier);
};
