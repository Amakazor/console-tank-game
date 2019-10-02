#pragma once

#include "incude.h"

class tile
{
protected:
	std::string type;
	
	bool passable;
	int  ap_cost;

	int  cover;			//in percent
	bool destructible;
	bool hp;

	std::string after_destruct_type;

public:
	
	tile();

	bool provides_cover();

	bool has_covered();

	bool is_destructible();

	int  shot(int damage); //returns new hp

	bool is_passable();

	int  get_ap_cost();

	std::string destroy();
};

