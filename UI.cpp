#include "UI.h"



void UI::printDogRepository()
{
	this->printRepository(this->repository);
}

UI::UI(DogRepository* repo)
{
	this->repository = repo;

	this->csvFile = new CSVFile("adoptions.csv");
	this->htmlFile = new HTMLFile("adoptions.html");

}


UI::~UI()
{
	delete this->repository;
}

Dog UI::readDog(const char * msg)
{
	std::cout << msg;

	std::string breed = "NoBreed";
	std::string name = "NoName";
	std::string image_link = "NoImageLink";
	unsigned int age = 0;

	std::cout << "Breed: ";
	std::cin >> breed;

	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Image Link: ";
	std::cin >> image_link;

	age = this->readInt("Age: ");

	Dog result = Dog(breed, name, image_link, age);

	DogValidator validator;
	try {
		validator.validate(result);
		return result;
	}
	catch (DogException& e)
	{
		std::vector<std::string> err = e.get();
		for (int i = 0; i < err.size(); i++)
			std::cout << err.at(i) << "\n";
		system("PAUSE");
	}

	return NULL_DOG;
}

unsigned int UI::readInt(const char * msg)
{
	unsigned int res;
	std::cout << msg;
	std::cin >> res;
	return res;
}

void UI::loadAdoptionList()
{
	switch (this->fileType)
	{
	case HTML:
		this->adoptionList = this->htmlFile->read();
		break;
	case CSV:
		this->adoptionList = this->csvFile->read();
		break;
	default:
		break;
	}
}

void UI::saveAdoptionList()
{
	switch (this->fileType)
	{
	case HTML:
		this->htmlFile->write(this->adoptionList);
		break;
	case CSV:
		this->csvFile->write(this->adoptionList);
		break;
	default:
		break;
	}
}

void UI::printRepository(DogRepository * repo)
{
	for (int i = 0; i < repo->getSize(); i++)
		std::cout << repo->get(i).toString() << std::endl;

	system("PAUSE");
	this->cls();
}


void UI::addDogMenu()
{
	Dog toAdd = this->readDog("Read Dog: \n");

	if (toAdd != NULL_DOG) {
		this->repository->add(toAdd);
		std::cout << "The dog was added succeffuly.\n";
		system("PAUSE");
	}

	this->cls();
}

void UI::removeDogMenu()
{
	this->cls();

	std::cout << "1 - Remove dog at index\n";
	std::cout << "2 - Remove dog\n";
	std::cout << "0 - Back\n";

	unsigned int command = 0;
	std::cout << "Command: ";
	std::cin >> command;

	Dog toRemove = Dog();
	unsigned int index = 0;

	switch (command)
	{
	case 1:

		std::cout << "Index: ";
		index = this->readInt("Index: ");
		if (this->repository->remove(index))
			std::cout << "The dog was removed succesfuly.\n";
		else
			std::cout << "Could not remove the dog at index\n" << index;

		system("PAUSE");
		this->cls();

		break;


	case 2:

		toRemove = this->readDog("Dog to remove: \n");
		if (toRemove != NULL_DOG)
			if (this->repository->remove(toRemove))
				std::cout << "The dog was removed succesfuly.\n";
			else
				std::cout << "Could not remove the dog:\n " << toRemove.toString() << "\n";

		system("PAUSE");
		this->cls();

		break;


	default:
		std::cout << "unkonwn command!\n";
		system("PAUSE");
		this->cls();
		this->removeDogMenu();
		break;
	}
}

void UI::updateDogMenu()
{

	Dog toUpdate = this->readDog("Read the dog to update: \n");
	Dog updateWith = this->readDog("Read the dog to update with: \n");

	if (toUpdate == NULL_DOG || updateWith == NULL_DOG)
	{
		std::cout << "The dog couldnot be updated!\n";
		system("PAUSE");
		return;
	}

	if (this->repository->update(toUpdate, updateWith))
		std::cout << "The dog was updated !\n";
	else
		std::cout << "The dog couldnot be updated!\n";

	system("PAUSE");
	this->cls();
}

void UI::adminMode()
{
	while (true) 
	{
		this->cls();

		std::cout << "1 - Add dog\n";
		std::cout << "2 - Update dog\n";
		std::cout << "3 - Remove dog\n";
		std::cout << "4 - Print all dogs\n";
		std::cout << "0 - Back\n";

		unsigned int command = 0;
		std::cout << "Command: ";
		std::cin >> command;

		switch (command)
		{
		case 1:
			this->addDogMenu();
			break;

		case 2:
			this->updateDogMenu();
			break;

		case 3:
			this->removeDogMenu();
			break;

		case 4:
			this->printDogRepository();
			break;

		case 0:
			return;
			break;

		default:
			std::cout << "Unkown command\n";
			system("PAUSE");
			break;
		}
	}
}

void UI::searchByBreed()
{
	std::string breed;
	unsigned int age = 0;

	std::cout << "Search by breed: \n";
	std::cout << "Breed: ";
	std::cin >> breed;

	std::cout << "Less than age: ";
	std::cin >> age;

	DogRepository* dogWithBreed = getDogsWithBreed(this->repository, breed);
	DogRepository* result = getDogsWithAgeLessThan(dogWithBreed, age);

	this->printRepository(result);

	delete dogWithBreed;
	delete result;
}

void UI::userMode()
{


	unsigned int curentDog = 0;
	this->loadAdoptionList();

	while (true) {

		this->cls();

		std::cout << "Client Mode: \n";

		// Print the curent dog to the screen

		std::cout << "Name: " << this->repository->get(curentDog).getName() << std::endl;
		std::cout << "Breed: " << this->repository->get(curentDog).getBreed() << std::endl;
		std::cout << "Image Link: " << this->repository->get(curentDog).getImageLink() << std::endl;
		std::cout << "Age: " << this->repository->get(curentDog).getAge() << std::endl;

		std::cout << "1 - Adopt | 2 - Next | 3 - Search by breed | 4 - Show adoption list | 0 - Quit" << std::endl;

		unsigned int command = 0;
		std::cout << "Command: ";
		std::cin >> command;

		switch (command)
		{
		case 1:

			this->adoptionList->add(this->repository->get(curentDog));
			this->repository->remove(curentDog);
			std::cout << "You adopted " << this->repository->get(curentDog).getName() << std::endl;
			this->saveAdoptionList();
			system("PAUSE");
			break;

		case 2:

			if (curentDog < repository->getSize())
				curentDog++;
			else
				curentDog = 0;

			break;

		case 3:

			this->searchByBreed();

			break;

		case 4:

			if (this->fileType == HTML)
				system("adoptions.html");
			else
				system("notepad.exe adoptions.csv");

			break;

		case 0:

			return;

			break;

		default:
			std::cout << "Unkown command\n";
			system("PAUSE");
			break;
		}
	}

}

void UI::printMainMenu()
{
}

void UI::start()
{
	bool sellecting = true;
	while (sellecting) {
		this->cls();
		int type = 0;

		std::cout << "Sellect file format: \n";
		std::cout << "1 - HTML \n";
		std::cout << "2 - CSV \n";
		std::cout << "0 - QUIT \n";

		std::cin >> type;

		switch (type)
		{
		case 1:
			this->fileType = HTML;
			sellecting = false;
			break;
		case 2:
			this->fileType = CSV;
			sellecting = false;
			break;
		case 0:
			return;
			break;
		
		default:
			std::cout << "Unkown command\n";
			system("PAUSE");
			break;
		}
	}

	HTMLFile *dogsFile = new HTMLFile("dogs.html");
	this->repository = dogsFile->read();

	while (true)
	{
		this->cls();

		std::cout << "1 - Admin Mode\n";
		std::cout << "2 - User Mode\n";
		std::cout << "0 - Exit\n";

		unsigned int command = 0;
		std::cout << "Command: ";
		std::cin >> command;

		if (command == 1)
		{
			adminMode();
		}
		else
			if (command == 2)
			{
				userMode();
			}
			else
				if (command == 0)
				{
					dogsFile->write(this->repository);
					return;
				}
				else
				{
					std::cout << "Unkown command\n";
					system("PAUSE");
				}
	}

}

void UI::cls()
{
	system("@cls||clear");
}
