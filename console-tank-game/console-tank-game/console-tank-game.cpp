#define _WIN32_WINNT 0x0500

#include "incude.h"
#include "engine.h"


int main()
{
	std::unique_ptr<engine> game_engine = std::unique_ptr<engine>(new engine);
	game_engine->game_loop();
	/*
	stage_controller *game1 = new stage_controller;
	game1->generate_stage("stage1.txt");

	int i = 0;
	char character = ' ';
	
	while (i < 99999999)
	{
		std::cout << game1->stage_to_string();
		if (_kbhit())
		{
			character = _getch();
		}
		std::cout << character;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		cls();
		i++;
		if (character == 'p')
		{
			break;
		}
	}

	return 0;
	*/
}