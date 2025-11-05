#pragma once
#include "Construction.h"

using namespace std;

class Quartier : public Construction {
	bool valide;
public:
	bool est_valide(vector<Construction&>);
	string get_type_construction();
	Quartier(int, valide);
	Quartier(const Quartier&);
	Quartier& operator+(const Quartier&);

};
