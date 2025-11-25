#include "Partie.h"
#include <iostream>
#include <limits> 

Partie* Partie::instance = nullptr;

Partie& Partie::get_instance(int j, bool c, const bool var[5], const std::vector<std::string>& noms) {
    if (instance == nullptr) instance = new Partie(j, c, var, noms);
    return *instance;
}

Partie& Partie::get_instance() { return *instance; }

Partie::Partie(int j, bool c, const bool var[5], const std::vector<std::string>& noms): nb_joueurs(j), courante(c){
    for (int i = 0; i < 5; ++i) variantes[i] = var[i];
    chantier = new Chantier(nb_joueurs);
    int taille_noms = noms.size();
    for (int i = 0; i < nb_joueurs; ++i) {
        std::string nom = (i < taille_noms) ? noms[i] : "Joueur " + std::to_string(i + 1);
        Joueur* nouveau = new Joueur(i, nom);
        nouveau->ajouter_pierres(i + 1);
        joueurs.push_back(nouveau);
    }
}
Partie::~Partie() {
    for (auto j : joueurs) delete j;
    delete chantier;
    instance = nullptr;
}

bool Partie::setCourante() { courante = true; return courante; }
int Partie::getNbJoueurs() const { return nb_joueurs; }
std::vector<Joueur*> Partie::determiner_classement() {
    for (auto j : joueurs) j->maj_score();
    std::vector<Joueur*> cl = joueurs;
    std::sort(cl.begin(), cl.end(), [](Joueur* a, Joueur* b) { return a->get_score() > b->get_score(); });
    return cl;
}

void Partie::jouer() {
    std::string input;
    while (courante && !chantier->est_vide()) {
        for (Joueur* j : joueurs) {
            if (!courante) break;
            std::cout << "\n-----------------------------------" << std::endl;
            std::cout << "TOUR DE : " << j->getNom() << " (Pierres: " << j->get_nb_pierres() << ")" << std::endl;
            chantier->afficher_chantier();
            bool tour_termine = false;
            while (!tour_termine) {
                int index_tuile = -1;
                std::cout << "> Choisir tuile (0-" << chantier->get_taille() - 1 << ") ou 'save'/'quit' : ";
                std::cin >> input;
                if (input == "quit") { courante = false; break; }
                if (input == "save") { std::cout << "Sauvegarde..." << std::endl; courante = false; break; }
                try {
                    index_tuile = std::stoi(input);
                }
                catch (...) {
                    std::cout << "Entree invalide." << std::endl;
                    continue; 
                }
                if (!j->choisir_tuile(index_tuile, *chantier)) {
                    std::cout << "Choix impossible (Index invalide ou pas assez de pierres)." << std::endl;
                    continue; 
                }
                bool placement_confirme = false;
                while (!placement_confirme) {
                    int x, y;
                    std::cout << "> Coordonnees (X Y) : ";
                    std::cin >> x >> y;
                    j->placer_tuiles_temporairement(Coordonnee(x, y), Coordonnee(x + 1, y), Coordonnee(x, y + 1), nullptr);
                    j->afficher_cite();
                    std::cout << "> Action ? (tourner / changer / confirmer) : ";
                    std::cin >> input;
                    if (input == "tourner") {
                        j->tourner_tuile_temporaire();
                        std::cout << "Rotation effectuee." << std::endl;
                    }
                    else if (input == "changer") {
                        std::cout << "Retour au choix de la tuile..." << std::endl;
                        break;
                    }
                    else if (input == "confirmer") {
                        j->confirmer_emplacement(*chantier);
                        j->maj_score();
                        std::cout << "Coup valide !" << std::endl;
                        placement_confirme = true;
                        tour_termine = true; 
                    }
                }
            }
        }
        if (courante) {
            chantier->maj_chantier();
        }
    }
    std::cout << "=== PARTIE TERMINEE ===" << std::endl;
    determiner_classement();
}