#pragma once
#include "../abstract/Construction.h"
#include <string>


class Carriere : public Construction  {
public:
	std::string get_type_construction () const override;
	
	Carriere(int id);
	Carriere(const Carriere& c);
	Carriere& operator=(const Carriere& c); /*erreur sur cette ligne*/
	~Carriere() = default;


};
