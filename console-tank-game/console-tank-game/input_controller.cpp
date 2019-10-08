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

char input_controller::get_current_input()
{
	char _char = *current_input;
	*this->current_input = ' ';
	return _char;
}
