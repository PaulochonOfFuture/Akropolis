#pragma once
#include "../abstract/Construction.h"
#include <string>


class Carriere : public Construction  {
public:
	std::string get_type_construction();
	const void override(); /*pas sur du type*/
	Carriere(int id);
	Carriere(const Carriere& c);
	Carriere& Carriere(const Carriere& c); /*erreur sur cette ligne*/
	~Carriere() = default;


};
