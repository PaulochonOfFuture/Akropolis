#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm> 
#include "Joueur.h"
#include "Chantier.h" 

class Partie {
private:
    static Partie* instance;
    const int nb_joueurs;
    bool courante;
    bool variantes[5];
    std::vector<Joueur*> joueurs;
    Chantier* chantier; 
    Partie(int j, bool c, const bool var[5], const std::vector<std::string>& noms);
public:
    Partie(const Partie&) = delete;
    void operator=(const Partie&) = delete;
    ~Partie();
    static Partie& get_instance(int j, bool c, const bool var[5], const std::vector<std::string>& noms);
    static Partie& get_instance();
    bool setCourante();
    int getNbJoueurs() const;
    std::vector<Joueur*> determiner_classement();
    void jouer();
};