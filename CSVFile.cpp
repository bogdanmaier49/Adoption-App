#include "CSVFile.h"



DogRepository* CSVFile::read()
{
	DogRepository* result = new DogRepository();

	std::ifstream file(this->fileName);
	std::string line;

	while (std::getline(file, line))
	{
		std::vector<std::string> splitLine = split(line, ',');

		std::string name = splitLine.at(0);
		std::string breed = splitLine.at(1);
		std::string image_link = splitLine.at(2);
		unsigned int age = std::stoi((splitLine.at(3)));



		if (breed.size() >= 3 || name.size() >= 3 || image_link.size() >= 6)
			result->add(Dog(breed, name, image_link, age));
	}

	file.close();
	return result;
}

void CSVFile::write(DogRepository* repo)
{
	std::ofstream file(fileName);

	for (int i = 0; i < repo->getSize(); i++)
	{
		file << repo->get(i).toString() << "\n";
	}

	file.close();
}