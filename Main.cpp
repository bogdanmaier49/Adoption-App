#include "UI.h"
#include "CSVFile.h"
#include <string>

void generateHTMLFileWithDogs()
{
	HTMLFile* file = new HTMLFile("dogs.html");
	DogRepository* repo = new DogRepository();

	std::vector<std::string> names = std::vector<std::string>();
	names.push_back("Leia");
	names.push_back("Luke");
	names.push_back("Vader");
	names.push_back("Yoda");
	names.push_back("Harry");
	names.push_back("Frodo");
	names.push_back("DarkLord");
	names.push_back("Dracula");
	names.push_back("YoMama");
	names.push_back("Ionut");

	std::vector<std::string> breeds = std::vector<std::string>();
	breeds.push_back("Golden");
	breeds.push_back("German");
	breeds.push_back("Pug");
	breeds.push_back("Kanye");
	breeds.push_back("Dogo");
	breeds.push_back("Doge");
	breeds.push_back("Chewbaka");

	std::vector<std::string> links = std::vector<std::string>();
	links.push_back("www.chewbaka.jpg");
	links.push_back("www.doge.jpeg");
	links.push_back("www.golden.jpg");
	links.push_back("www.pug.jpg");
	links.push_back("www.yoda.jpg");
	links.push_back("www.german.jpg");


	for (int i = 0; i < 200; i++)
	{
		std::string breed = breeds.at(rand() % breeds.size());
		std::string name = names.at(rand() % names.size());
		std::string link;

		if (breed == "Golden")
			link = "www.golden.jpg";
		else
			if (breed == "German")
				link = "www.german.jpg";
			else
				if (breed == "Pug")
					link = "www.pug.jpg";
				else
					if (breed == "Dogo")
						link = "www.yoda.jpg";
					else
						if (breed == "Doge")
							link = "www.doge.jpeg";
						else
							if (breed == "Chewbaka")
								link = "www.chewbaka.jpg";
							else
								link = links.at(rand() % links.size());

		int age = rand() % 20 + 1;

		repo->add(Dog(breed, name, link, age));

	}

	file->write(repo);
}

int main()
{

	//generateHTMLFileWithDogs();

	
	DogRepository* repo = new DogRepository();
	UI ui = UI(repo);
	ui.start();
	
	

	return 0;
}