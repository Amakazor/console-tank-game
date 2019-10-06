#include "input_controller.h"

void input_controller::capture_input()
{
	char character = ' ';

	if (_kbhit())
	{
		character = _getch();

		if (isalpha(character))
		{
			*this->current_input = character;
		}
	}
}

std::shared_ptr<char> input_controller::get_current_input()
{
	return current_input;
}
