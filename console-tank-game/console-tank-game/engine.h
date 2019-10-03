#pragma once
#include "incude.h"
#include "stage_controller.h"

class engine
{
protected:
	std::string gamename = "====== TANK GAME PROTOTYPE ======";

	unsigned int gamestate = 1;

	std::unique_ptr<stage_controller> game_stage_controller = std::unique_ptr<stage_controller>(new stage_controller);

	bool file_exists(std::string filename);

	void menu();

	void file_loader();

public:

	void init();

	void game_loop();

	void set_game_state(unsigned int _gamestate);

	unsigned int get_game_state();

	std::string get_game_name();
};

