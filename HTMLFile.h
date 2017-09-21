#pragma once
#include "File.h"

class HTMLFile : public File
{
private:
	std::string addTableRow(std::vector<std::string> data);
public:
	HTMLFile(const char* fileName) : File(fileName) {}
	DogRepository* read();
	void write(DogRepository* repo);

	bool isRowTag(std::string line);
	bool isEndRowTag(std::string line);

	bool isImage(std::string line);

	std::string getData(std::string line);
	std::string getLink(std::string line);
};

