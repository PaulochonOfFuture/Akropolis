#pragma once
#include "../plateau/Cite.h"
#include "../plateau/Chantier.h"
#include "../exceptions/JoueurException.h"
#include <string>
#include<memory>
class Joueur {
private:
    std::unique_ptr<Cite> cite;
    int score;
    int nb_pierres;
    std::string nom;
    const int id_joueur;
    const std::string nom;
    int score;
    Cite* cite;

public:
    Joueur(int longueur, int largeur, int pierres, const std::string& nom): cite(std::make_unique<Cite>(longueur, largeur)),score(0),nb_pierres(pierres),nom(nom), id_joueur(0){}
    void maj_score();
    void debiter_pierres(int nb){score = score - nb;}
    void set_score(int s) { score = s; }
    int get_score() { return score; }
    void placer_tuiles_temporairement(Coordonnee& c1, Coordonnee& c2, Coordonnee& c3, Tuile* t);
    void confirmer_emplacement(Chantier& chantier);
    Tuile* choisir_tuile(int rang, Chantier& chantier);// pas besoin de la mettre dans joueur (?)

    //void ajouter_tuile();
   // void ajouter_pierres();
   //int get_nb_pierres();    
   //void tourner_tuile_temporaire();
};
