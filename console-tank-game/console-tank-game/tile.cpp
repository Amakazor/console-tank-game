#include "incude.h"
#include "tile.h"

tile::tile()
{
}

bool tile::provides_cover()
{
	return (bool)this->cover;
}

bool tile::has_covered()
{
	std::random_device random_device; // obtain a random number from hardware
	std::mt19937 engine(random_device()); // seed the generator
	std::uniform_int_distribution<> distribution(0, 100); // define the range

	int generated_number = distribution(engine); //genetate number from range using engine
	return generated_number > tile::cover;
}

bool tile::is_destructible()
{
	return tile::destructible;
}

int tile::shot(int damage)
{
	tile::hp -= damage;
	return tile::hp;
}

bool tile::is_passable()
{
	return tile::passable;
}

int tile::get_ap_cost()
{
	return this->ap_cost;
}

std::string tile::destroy()
{
	return tile::after_destruct_type;
}