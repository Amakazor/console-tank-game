#pragma once
#include "incude.h"
#include "stage_controller.h"
#include "player_controller.h"

class player
{
private:
	char symbol;
	

	std::shared_ptr<stage_controller> stage_controller_reference;

	std::shared_ptr<player_controller> player_controller_reference;

public:
	player(char _symbol, std::shared_ptr<stage_controller> _stage_controller_reference, std::shared_ptr<player_controller> _player_controller_reference);

	
};

