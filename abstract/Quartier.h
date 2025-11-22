#pragma once
#include "Construction.h"
#include <vector>

class Quartier : public Construction {
protected:
	bool valide;
	virtual bool est_valide(std::vector<Construction*>& voisins) = 0;
	std::string get_type_construction() const override = 0;
public:
	Quartier(int i, bool v);
	//Quartier(const Quartier& q);
	//Quartier& operator=(const Quartier& q);

};
