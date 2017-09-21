#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include "DogRepository.h"

class File
{
protected:
	const char* fileName;
public:
	File(const char* fileName);
	File() {}
	~File();

	virtual DogRepository* read(void) = 0;
	virtual void write(DogRepository* repo) = 0;
};

std::vector<std::string> split(const std::string &s, char delim);