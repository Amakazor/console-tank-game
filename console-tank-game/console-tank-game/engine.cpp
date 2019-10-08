#include "engine.h"

bool engine::file_exists(std::string filename)
{
	std::ifstream f(filename.c_str());
	return f.good();
}

void engine::menu()
{
	std::string menu_string =
		"################################\n"
		"############# MENU #############\n"
		"################################\n";

	menu_string += !this->game_stage_controller->get_stage_name().empty() ? "1. " : "#. ";
	menu_string += "Start game\n";

	menu_string += "   (";
	menu_string += !this->game_stage_controller->get_stage_name().empty() ? this->game_stage_controller->get_stage_name() : "Stage file not loaded";
	menu_string += ")\n";

	menu_string += "2. Load stage file\n";
	menu_string += "9. Exit\n";
	menu_string += "################################\n";

	std::string user_input = "x";
	int user_input_int = 0;
	bool user_input_valid = TRUE;

	do
	{
		arek::cls();
		std::cout << this->get_game_name() << "\n\n";
		std::cout << menu_string;
		std::cout << "\n";

		if (!user_input_valid)
		{
			std::cout << "Wrong option!\n";
		}
		std::cout << "Select menu option: ";
		std::cin >> user_input;

		try
		{
			user_input_int = std::stoi(user_input);
		}
		catch (const std::exception&)
		{
			user_input_valid = FALSE;
		}

		if ((user_input_int == 2) || (user_input_int == 9) || ((user_input_int == 1) && (!this->game_stage_controller->get_stage_name().empty())))
		{
			user_input_valid = TRUE;
		}
		else
		{
			user_input_valid = FALSE;
		}

	} while (!user_input_valid);

	switch (user_input_int)
	{
	case 1:
		this->set_game_state(3);
		break;
	case 2:
		this->set_game_state(2);
		break;
	case 9:
		this->set_game_state(9999);
		break;
	default:
		break;
	}
}

void engine::file_loader()
{
	//GET FILE LIST
	std::string stage_list = "";
	for (const auto& entry : fs::directory_iterator(""))
	{
		std::string curr_file = entry.path().string();

		if (curr_file.find(".txt") != std::string::npos)
		{
			stage_list += "    ";
			stage_list += curr_file;
			stage_list += '\n';
		}
	}

	if (!stage_list.empty())
	{
		//GET FILE
		std::string filename = "";
		bool does_it_exist_really = TRUE;

		do
		{
			arek::cls();
			std::cout << this->get_game_name() << "\n\n";

			//OUTPUT FILE LIST
			std::cout << "Available stage files:" << '\n';
			std::cout << stage_list << '\n';

			if (does_it_exist_really)
			{
				std::cout << '\n';
				std::cout << "Enter stage filename or enter 9 to exit:" << '\n';
			}
			else
			{
				std::cout << '\n';
				std::cout << "Wrong filename!" << '\n';
				std::cout << "Enter stage filename or enter 9 to exit:" << '\n';
			}
			std::cin >> filename;

			if (filename == "9")
			{
				does_it_exist_really = FALSE;
				this->set_game_state(1);
				break;
			}
			else
			{
				does_it_exist_really = this->file_exists(filename);
				if (does_it_exist_really && filename.find(".txt") == std::string::npos)
				{
					does_it_exist_really = FALSE;
				}
			}

		} while (!does_it_exist_really);

		if (does_it_exist_really)
		{
			//LOAD STAGE
			this->game_stage_controller->generate_stage(filename);
			this->set_game_state(1);
		}
	}
	else
	{
		std::cout << "No stage files!" << '\n';
	}
}

void engine::init()
{
	this->game_loop();
}

void engine::game_loop()
{
	bool killswitch = FALSE;
	do 
	{
		switch (this->gamestate)
		{
		case 1:
			menu();
			break;
		case 2:
			this->file_loader();
			break;
		case 3:
			this->game_input_controller->capture_input();

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			arek::cls();
			break;
		case 9999:
			killswitch = TRUE;
			break;
		default:
			break;
		}
	} while (!killswitch);
}

void engine::set_game_state(unsigned int _gamestate)
{
	this->gamestate = _gamestate;
}

unsigned int engine::get_game_state()
{
	return this->gamestate;
}

std::string engine::get_game_name()
{
	return this->gamename;
}
