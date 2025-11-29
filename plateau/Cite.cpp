#include "Cite.h"
#include <set>

void Cite::afficher_cite() {}
Hexagone& Cite::recherche_hexagone(const Coordonnee& c) const {
	return *(carte.at(c));
}
void Cite::maj_cite(){

	//changer étage hexagone
	size_t i = 0;
    habitations.clear();

	for (const Coordonnee& c : position_temporaire) {
		carte.at(c)->set_constru(tuile_temporaire->get_constru(i)); //on maj l'hexagone
		i++;
        //hexagone mis a jour, on met a jour les chaines
        //il faut recalculer toutes les chaines


        for (auto& tuple : carte) {
            Coordonnee coord = tuple.first;
            Hexagone& hex = *tuple.second;
            if (hex.get_constru()->get_type_construction() == "Habitation") {

                Habitation* h = dynamic_cast<Habitation*>(hex.get_constru());
                std::vector<Habitation*> voisins = get_hab_voisins(coord);

                // aucun voisin,nouvelle chaîne 
                if (voisins.empty())
                {
                    Chaine_habitation nouvelle;
                    nouvelle += h;
                    nouvelle.set_longueur(nouvelle.get_longueur() + hex.get_etage());
                    int id = nouvelle.get_id_chaine();  // revoir la gestion d'id (pour l'instant statique, c'est mieux de mettre dans cité)
                    habitations[id] = nouvelle;
                }

                // au moins un voisin,fusion
                else
                {
                    std::set<int> ids_voisines;
                    for (Habitation* hv : voisins)
                        ids_voisines.insert(hv->getChaineMere());

                    int id_principal = *ids_voisines.begin();
                    Chaine_habitation& principale = habitations[id_principal];
                    for (int id : ids_voisines)
                    {
                        if (id != id_principal) {
                            principale += habitations[id];
                            habitations.erase(id);
                        }
                    }

                    // ajout de la nouvelle habitation
                    principale += h;
                    principale.set_longueur(principale.get_longueur() + hex.get_etage()); //on ajoute le nb d'etage a laquelle l'habitation est située
                }
            }
        }
    }


	
	set_tuile_temporaire(nullptr);
	position_temporaire.clear();

}
void Cite::set_tuile_temporaire(Tuile* t){
	tuile_temporaire = t;
}
void Cite::set_position_temporaire(std::vector<Coordonnee>& c){

	position_temporaire = c;
}
std::vector<Hexagone*> Cite::get_hab_voisins(const Coordonnee& c) const {
	std::vector<Hexagone*> hex_voisins;
	const auto& voisins = c.get_voisines();

	for (const Coordonnee& v : voisins) {
		if ((carte.at(v).get()->get_constru()->get_type_construction() == "Habitation"))
			hex_voisins.push_back(carte.at(v).get());

	}
	return hex_voisins;
}


std::vector<Hexagone*> Cite::get_voisins(const Coordonnee& c) const{
	std::vector<Hexagone*> hex_voisins;
	const auto& voisins = c.get_voisines();

	for (const Coordonnee& v : voisins) {

		hex_voisins.push_back(carte.at(v).get());

	}
	return hex_voisins;
}
