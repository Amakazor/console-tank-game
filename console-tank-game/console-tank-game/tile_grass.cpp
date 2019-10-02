#include "tile_grass.h"

tile_grass::tile_grass():tile::tile()
{
	tile::type = "Grass";

	tile::passable = true;
	tile::ap_cost = 2;

	tile::cover = 0;
	tile::destructible = false;
	tile::hp = 0;

	tile::after_destruct_type = "";
}