#pragma once
#include "Dog.h"
#include "DogRepository.h"
#include "DogRepositoryController.h"
#include <iostream>
#include <exception>
#include "CSVFile.h"
#include "HTMLFile.h"

enum FileType {
	HTML, CSV
};

class UI
{
private:

	DogRepository* repository;
	DogRepository* adoptionList;

	Dog readDog(const char* msg);
	unsigned int readInt(const char* msg);

	FileType fileType;
	HTMLFile* htmlFile;
	CSVFile* csvFile;

	void loadAdoptionList();
	void saveAdoptionList();

	/*
		Prints a given dog repository.
	*/
	void printRepository(DogRepository* repo);

	/*
	Admin Mode
	*/

	void adminMode();

	void addDogMenu();
	void removeDogMenu();
	void updateDogMenu();

	/*
	User Mode
	*/

	void userMode();
	void searchByBreed();

public:

	/*
		Prints the main menu
	*/
	void printMainMenu();

	/*
		Starts the ui.
	*/
	void start();

	/*
		Clears the console screen.
	*/
	void cls();

	/*
		Prints the curent dog repository.
	*/
	void printDogRepository();

	UI(DogRepository* repo);
	~UI();

	inline DogRepository* getDogRepository() { return this->repository; }
};

