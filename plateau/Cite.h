#pragma once
#include "Hexagone.h"
#include "Tuile.h"
#include "Coordonnee.h"
#include "ChaineHabitation.h"
#include <map>
#include <memory>

class Cite {
private:
    std::map<int, Chaine_habitation> habitations;
    std::map<Coordonnee, std::unique_ptr<Hexagone>> carte;
    Tuile* tuile_temporaire;
    std::vector<Coordonnee> position_temporaire; 
    //pour le constructeur: faire une initialisation puis dans le corps faire une methode initialiser_tuile qui crée toutes les constructions
    //il faudra gérer le fait de séparer une chaine d'habitation (ou pas)
 
public:
    Cite(int longueur, int largeur) : tuile_temporaire(nullptr) {
        for (int x = 0; x < longueur; x++) {
            for (int y = 0; y < largeur; y++) {
                Coordonnee c = Coordonnee(x,y);
                carte[c] = std::unique_ptr<Hexagone>();
            }
        }
    }
    std::vector<Hexagone*>get_hab_voisins(const Coordonnee& c) const;
    std::map<int, Chaine_habitation>& get_habitations() { return habitations; }
    void afficher_cite();
    Hexagone& recherche_hexagone(const Coordonnee& c) const;
    void maj_cite();
    void set_tuile_temporaire(Tuile* t);
    const std::vector<Coordonnee>& get_position_temporaire() const { return position_temporaire; }
    void set_position_temporaire(std::vector<Coordonnee>& t);
    std::vector<Hexagone*> get_voisins(const Coordonnee& c) const; 
    const std::map<Coordonnee, std::unique_ptr<Hexagone>>& get_carte() const { return carte; }

};
