#pragma once
#include "Tuile.h"
#include <vector>


// ?????
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




using namespace std;

class Chantier
{
private:
    const int taille_max_chantier = 5; // nb max de tuile dans la rivière (début de tour) ; diminue à chaque fois qu'un joueur joue.
    vector<tuile> pioche;              // toutes les tuiles de la pioche
    const int indice_premiere_tuile;   //
public:
    explicit Chantier(int max);        // constructeur du Chantier
    ~Chantier() = default;             // destructeur (par defaut) du Chantier

    int calculer_cout_tuile_i(int i) const;  // Calcule le coût d'une tuile à la position i dans la rivière ; pas sur qu'il faut laisser const.
    void afficher_chantier() const;  // Affiche la rivière courante (les tuiles disponibles) ; pas sur qu'il faut laisser const.
    void maj_chantier();             // Met à jour la rivière pour le tour suivant
}chantier;
