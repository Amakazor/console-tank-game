#include "incude.h";

#pragma once
class csv
{
public:
	static std::map<std::string, std::vector<std::string>> read_file(std::string filename, std::string delimiter);
};

