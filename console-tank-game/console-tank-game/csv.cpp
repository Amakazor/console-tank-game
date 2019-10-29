#include "csv.h"

std::map<std::string, std::vector<std::string>> csv::read_file(std::string filename, std::string delimiter)
{
	std::map<std::string, std::vector<std::string>> content;

	std::ifstream file;

	file.open(filename, std::fstream::in);
	if (file.is_open())
	{
		std::string line;

		while (std::getline(file, line) && !file.eof())
		{
			std::vector<std::string> string_vector;
			size_t position = 0;
			std::string identifier;

			while ((position = line.find(delimiter)) != std::string::npos)
			{
				string_vector.push_back(line.substr(0, position));
				line.erase(0, position + delimiter.length());
			}

			if (!string_vector.empty())
			{
				identifier = string_vector.at(0);
				string_vector.erase(string_vector.begin());

				content.insert(std::pair<std::string, std::vector<std::string>>(identifier, string_vector));
			}
		}
	}
	else throw(ENOENT);

	return content;
}