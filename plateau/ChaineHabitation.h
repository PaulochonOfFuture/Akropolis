#pragma once
#include <vector>
#include "Habitation.h"

class Chaine_habitation {
private:
    std::vector<Habitation*> habitations;
    int id_chaine;
    int longueur;

    // compteur global pour générer des id uniques
    static int next_id;

public:

    // Getters
    const std::vector<Habitation*>& get_habitations() const {
        return habitations;
    }

    int get_id_chaine() const {
        return id_chaine;
    }

    int get_longueur() const {
        return longueur;
    }

    // Constructeurs
    Chaine_habitation(std::vector<Habitation*> habitations_, int id_chaine_, int longueur_)
        : habitations(std::move(habitations_)),
          id_chaine(id_chaine_),
          longueur(longueur_)
    {}

    Chaine_habitation()
        : habitations(),
          id_chaine(next_id++),   // id généré automatiquement
          longueur(0)
    {}

    // Opérateur += (ajout d'une chaine)
    Chaine_habitation& operator+=(const Chaine_habitation& c2);

    // Opérateur += (ajout d'une habitation)
    Chaine_habitation& operator+=(Habitation* h);

    // Comparaison (relation d'ordre)
    bool operator>(const Chaine_habitation& c2);
};

// Initialisation du compteur d'id
int Chaine_habitation::next_id = 0;

