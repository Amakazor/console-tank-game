#include "tile_rubble.h"

tile_rubble::tile_rubble():tile::tile()
{
	tile::type = "Pile of Rubble";
	tile::symbol = (char)178;

	tile::passable = true;
	tile::ap_cost = 3;

	tile::cover = 0;
	tile::destructible = false;
	tile::hp = 0;

	tile::after_destruct_type = "";
}