#include "player.h"

player::player(char _symbol, std::shared_ptr<stage_controller> _stage_controller_reference, std::shared_ptr<player_controller> _player_controller_reference)
{
	this->symbol = _symbol;
	this->stage_controller_reference =_stage_controller_reference;
	this->player_controller_reference = _player_controller_reference;
}