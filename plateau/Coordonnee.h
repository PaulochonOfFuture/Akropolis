#pragma once

class Coordonnee {
private:
	int x;
	int y;
public: 
	std::vector<Coordonnee> get_coord_voisine();
	const bool operator>(const Coordonnee&);
};
