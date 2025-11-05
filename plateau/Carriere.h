#pragma once
#include "Construction.h"
#include <string>


class Carriere : public Construction  {
public:
	std::string get_type_construction();
	void override() { const };
	Carriere(int);
	Carriere(const Carriere&);
	Carriere& Carriere(const Carriere&);
	~Carriere() = default;


};
