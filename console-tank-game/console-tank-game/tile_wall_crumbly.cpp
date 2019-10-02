#include "tile_wall_crumbly.h"

tile_wall_crumbly::tile_wall_crumbly():tile::tile()
{
	tile::type = "Destructible Wall";
	tile::symbol = (char)197;

	tile::passable = false;
	tile::ap_cost = 0;

	tile::cover = 100;
	tile::destructible = true;
	tile::hp = 2;

	tile::after_destruct_type = "tile_rubble";
}