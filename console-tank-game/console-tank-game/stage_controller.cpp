#include "stage_controller.h"

std::shared_ptr<tile> stage_controller::generate_tile(std::string type)
{
	std::map<std::string, std::shared_ptr<tile>> tile_types;

	tile_types["tile_grass"] = std::shared_ptr<tile>(new tile_grass);
	tile_types["tile_concrete"] = std::shared_ptr<tile>(new tile_concrete);
	tile_types["tile_rubble"] = std::shared_ptr<tile>(new tile_rubble);
	tile_types["tile_wall_solid"] = std::shared_ptr<tile>(new tile_wall_solid);
	tile_types["tile_wall_crumbly"] = std::shared_ptr<tile>(new tile_wall_crumbly);

	return tile_types[type];
}

std::map<int, std::map<int, std::shared_ptr<tile>>> stage_controller::generate_stage(std::string filename)
{
	std::ifstream stage_file;
	stage_file.open(filename);

	std::string current_line = "";
	int x = 0;
	int y = 0;

	std::map<int, std::map<int, std::shared_ptr<tile>>> to_return;

	while (std::getline(stage_file, current_line))
	{
		if (current_line == "NEXT")
		{
			x++;
			y=0;
		}
		else if (current_line == "END")
		{
			break;
		}
		else
		{
			to_return[x][y] = this->generate_tile(current_line);
			y++;
		}
	}
	stage_file.close();

	this->stage = to_return;
	this->stage_name = filename;

	return to_return;
}

std::string stage_controller::stage_to_string()
{
	std::string output_string = "";

	for (int i = 0; i < this->stage.size(); i++)
	{
		for (int j = 0; j < this->stage[i].size(); j++)
		{
			std::shared_ptr<tile> temp_tile = this->stage[i][j];
			output_string += temp_tile->get_symbol();
			output_string += ' ';
		}
		output_string += '\n';
	}

	return output_string;
}

std::string stage_controller::get_stage_name()
{
	return this->stage_name;
}
