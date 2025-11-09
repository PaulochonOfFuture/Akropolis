#pragma once
#include <string>

class Construction {
protected:
	int id_tuile_mère;
	virtual std::string get_type_construction() const = 0;
public:
	const int get_id_mere();
	Construction(int id);
	Construction(const Construction& c);
	Construction& operator=(const Construction& c);
	virtual ~Construction() = default;



};