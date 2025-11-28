#pragma once
#include <string>

class Construction {
protected:
	int id_tuile_mere;
public:
	virtual std::string get_type_construction() const = 0;
	virtual bool est_valide() const { return false; }
	int get_id_mere() const { return id_tuile_mere;}

	Construction(int id) : id_tuile_mere(id) {}
	//Construction(const Construction& c) {;
	//Construction& operator=(const Construction& c);
	virtual ~Construction() = default;



};