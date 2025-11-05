#pragma once
#include "Construction.h"
#include <cstring>
using namespace std;

class Carriere : public Construction {
public:
	stirng get_type_construction();
	void override() { const };
	Carriere(int);
	Carriere(const Carriere&);
	Carriere& Carriere(const Carriere&);
	~Carriere() = default;


};
