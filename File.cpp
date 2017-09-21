#include "File.h"

std::vector<std::string> split(const std::string &s, char delim) {
	std::stringstream stream(s);
	std::string item;
	std::vector<std::string> tokens;
	while (std::getline(stream, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

File::File(const char * fileName) : fileName(fileName)
{ }

File::~File()
{
	delete this->fileName;
}
