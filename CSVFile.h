#pragma once

#include "File.h"

class CSVFile : public File
{
public:
	CSVFile(const char* fileName) : File(fileName) {}
	DogRepository* read();
	void write(DogRepository* repo);
};
