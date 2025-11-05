#pragma once
#include <string>

class Construction {
private:
	int id_tuile_mère;
public:
	const int get_id_mere();
	const std::string get_type_construction();
	Construction(int);
	Construction(const Construction&);
	Construction& operator=(const Construction&);
	virtual ~Construction() = default;



};