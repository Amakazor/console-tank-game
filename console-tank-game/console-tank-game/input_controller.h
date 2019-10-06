#pragma once
#include "incude.h"

class input_controller
{
protected:
	std::shared_ptr<char> current_input = std::make_shared<char>(new char(' '));

public:
	void capture_input();

	std::shared_ptr<char> get_current_input();
};

