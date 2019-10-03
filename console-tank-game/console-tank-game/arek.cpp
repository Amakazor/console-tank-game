#include "arek.h"

void arek::pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void arek::cls()
{
	arek::pos(0, 0);
	for (int j = 0; j < 100; j++)
	{
		std::cout << std::string(100, ' ');
	}
	arek::pos(0, 0);
}