#include "tile_wall_solid.h"

tile_wall_solid::tile_wall_solid():tile::tile()
{
	tile::type = "Solid Wall";
	tile::symbol = (char)206;

	tile::passable = false;
	tile::ap_cost = 0;

	tile::cover = 100;
	tile::destructible = false;
	tile::hp = 0;

	tile::after_destruct_type = "";
}