#include "HTMLFile.h"

std::string HTMLFile::addTableRow(std::vector<std::string> data)
{
	std::string result;

	result += "<tr>\n";
	for (int i = 0; i < data.size(); i++)
		result += "<td>" + data.at(i) + "</td>\n";
	result += "</tr>\n";

	return result;
}

DogRepository * HTMLFile::read()
{
	DogRepository* result = new DogRepository();
	std::ifstream file(this->fileName);

	bool canRead = false;
	std::vector<std::string> dogData = std::vector<std::string>();
	std::string line;
	int index = 0;

	while (std::getline(file, line))
	{
		if (this->isEndRowTag(line)) {
			result->add(Dog(dogData.at(1), dogData.at(0), dogData.at(2), std::stoi(dogData.at(3))));
			dogData.clear();
			canRead = false;
		}
		if (canRead) {
			if (this->isImage(line))
				dogData.push_back(this->getLink(line));
			else 
				dogData.push_back(this->getData(line));
		}
		if (this->isRowTag(line)) {
			canRead = true;
		}


	}

	file.close();
	return result;
}

void HTMLFile::write(DogRepository * repo)
{

	std::ofstream file(this->fileName);

	file << "<!DOCTYPE html>\n";

	file << "<head>\n";
	file << "<link rel='stylesheet' type='text/css' href='style.css'>\n";
	file << "<title> Rent a Dog </title>\n";
	file << "</head>\n";

	file << "<body background='images/back.png' background-size= '80px 60px'>\n";

	file << "<center>\n";
	file << "<table> \n";

	for (int i = 0; i < repo->getSize(); i++)
	{
		std::vector<std::string> row;
		Dog d = repo->get(i);

		row.push_back(d.getName());
		row.push_back(d.getBreed());
		row.push_back("<img src = 'images/"+ d.getImageLink() +"' style = 'width:100px;height:100px;'>");
		row.push_back(std::to_string(d.getAge()));

		file << this->addTableRow(row);
	}

	file << "</table>\n";
	file << "</center>\n";
	file << "</body>\n";

	file << "</html>";

	file.close();

}

bool HTMLFile::isRowTag(std::string line)
{
	if (line.find("<tr>") == 0)
		return true;
	return false;
}

bool HTMLFile::isEndRowTag(std::string line)
{
	if (line.find("</tr>") == 0)
		return true;
	return false;
}

bool HTMLFile::isImage(std::string line)
{
	if (line.find("img") != std::string::npos)
		return true;
	return false;
}

std::string HTMLFile::getData(std::string line)
{
	std::string result = line;

	result.erase(0, result.find('>') + 1);
	result.erase(result.find('<'), result.size());



	return result;
}

std::string HTMLFile::getLink(std::string line)
{
	std::string result = line;

	result.erase(0, result.find('/') + 1);
	result.erase(result.find("'"), result.size());

	return result;
}
