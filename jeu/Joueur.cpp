#include "Joueur.h"
#include <vector>
#include <set>
void Joueur::confirmer_emplacement(Chantier& chantier){
	cite->maj_cite();
	chantier.maj_chantier();

}
void Joueur::placer_tuiles_temporairement(Coordonnee& c1, Coordonnee& c2, Coordonnee& c3, Tuile* t) {

    // Important : Ne pas oublier de catch() dans Jouer.
	if (not(trio_coordonnees_voisines(c1, c2, c3))){
        throw JoueurException("Ce ne sont pas 3 coordonnées voisines.");
    }
    else{
        //Vérifier si on ne pose pas dans le vide, si c'est dans la continuité du reste de la Cité :
        bool continuite = false;
        for (const Coordonnee c : c1.get_voisines()){
            if (not((cite->recherche_hexagone(c)).get_est_vide()) && not(c==c1)) {
                continuite = true;
            }
        }
        for (const Coordonnee c : c2.get_voisines()){
            if (not((cite->recherche_hexagone(c)).get_est_vide()) && not(c==c2)) {
                continuite = true;
            }
        }
        for (const Coordonnee c : c3.get_voisines()){
            if (not((cite->recherche_hexagone(c)).get_est_vide()) && not(c==c3)) {
                continuite = true;
            }
        }

        if (not(continuite)){
            throw JoueurException("Impossible de poser ici, il faut que ce soit dans la continuité du reste de la Cité.");
        }
        else {
            Hexagone& h1 = cite->recherche_hexagone(c1);
            Hexagone& h2 = cite->recherche_hexagone(c2);
            Hexagone& h3 = cite->recherche_hexagone(c3);

            //Vérifier si tout les Hexagones sur lesquels on construit sont vides :
            if ((h1.get_est_vide()) && (h2.get_est_vide()) && (h3.get_est_vide())){
                std::vector<Coordonnee> temp = { c1, c2, c3 };
                cite->set_position_temporaire(temp);
            }
            else{
                //Vérification de l'uniformité de l'étage des Hexagones sur lesquelles on construit:
                bool etage_uniforme = (h1.get_etage() == h2.get_etage()) && (h2.get_etage() == h3.get_etage());

                // Vérifier qu'on construit à cheval entre deux tuiles :
                bool a_cheval = ((h1.get_constru())->get_id_mere() != (h2.get_constru())->get_id_mere())
                            || ((h2.get_constru())->get_id_mere() != (h3.get_constru())->get_id_mere())
                            || ((h3.get_constru())->get_id_mere() != (h1.get_constru())->get_id_mere());

                if (not(etage_uniforme)){
                    throw JoueurException("Impossible de construire sur plusieurs étages à la fois.");
                }else if (not(a_cheval)){
                    throw JoueurException("Impossible de superposer deux Tuiles.");
                }else{
                    std::vector<Coordonnee> temp = { c1, c2, c3 };
                    cite->set_position_temporaire(temp);
                }
            }
        }
    }
}

Tuile* Joueur::choisir_tuile(int rang, Chantier& chantier) {

	if (chantier.calculer_cout_tuile_i(rang) > nb_pierres)
		throw JoueurException("Cette tuile est trop chère.");
	cite->set_tuile_temporaire(chantier.get_tuile(rang));
}
void Joueur::maj_score() {

    auto& chaines = cite->get_habitations();

    for (auto& tuple : cite->get_carte()) {

        const Coordonnee& coord = tuple.first;
        Hexagone& hex = cite->recherche_hexagone(coord);

        if (hex.get_constru()->get_type_construction() != "Habitation") // a voir, car habitation a aussi une methode est valide qui doit servir. on peut juste mettre a false tout le temps, ainsi le premier if est inutile
        {
            if (hex.get_constru()->est_valide()) {
                score += hex.get_etage();
            }
      
        }
    }

    
    int max = 0;
    for (auto& tuple : chaines) {
        
            if (tuple.second > max)
                max = tuple.second.get_longueur();
        }
    score += max;
    }

