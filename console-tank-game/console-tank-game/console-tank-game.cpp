#define _WIN32_WINNT 0x0500

#include "incude.h"
#include "engine.h"

int main()
{
	std::unique_ptr<engine> game_engine = std::unique_ptr<engine>(new engine);
	game_engine->init();
}