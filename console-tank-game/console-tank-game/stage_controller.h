#pragma once

#include "incude.h"
#include "tile.h"
#include "all_tiles.h"

class stage_controller
{
protected:
	std::string stage_name = "";
	std::map<int, std::map<int, std::shared_ptr<tile>>> stage;

	std::shared_ptr<tile> generate_tile(std::string type);

public:
	std::map<int, std::map<int, std::shared_ptr<tile>>> generate_stage(std::string filename);

	std::string stage_to_string();

	std::string get_stage_name();
};

