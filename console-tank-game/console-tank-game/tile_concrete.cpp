#include "tile_concrete.h"

tile_concrete::tile_concrete() :tile::tile()
{
	tile::type = "Concrete";

	tile::passable = true;
	tile::ap_cost = 1;

	tile::cover = 0;
	tile::destructible = false;
	tile::hp = 0;

	tile::after_destruct_type = "";
}