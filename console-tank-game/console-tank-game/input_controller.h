#pragma once
#include "incude.h"

class input_controller
{
protected:
	std::shared_ptr<char> current_input = std::make_shared<char>(' ');

public:
	void capture_input();

	char get_current_input();
};

