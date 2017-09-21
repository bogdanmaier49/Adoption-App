#include "Dog.h"



Dog::Dog()
{
	this->name = "NoName";
	this->breed = "NoBreed";
	this->image_link = "NoImageLink";
	this->age = 0;
}

Dog::Dog(std::string breed, std::string name, std::string image_link, unsigned int age)
{
	this->name = name;
	this->breed = breed;
	this->image_link = image_link;
	this->age = age;
}


void Dog::setName(std::string newName)
{
	this->name = newName;
}

void Dog::setBreed(std::string newBreed)
{
	this->breed = newBreed;
}

void Dog::setImageLink(std::string newImageLink)
{
	this->image_link = newImageLink;
}

void Dog::setAge(unsigned int newAge)
{
	this->age = newAge;
}

std::string Dog::toString()
{
	return this->name + "," + this->breed + "," + this->image_link + "," + std::to_string(this->age);
}

void DogValidator::validate(const Dog & d)
{
	std::vector<std::string> errors;

	if (d.getBreed().size() < 3)
		errors.push_back("Dog breed must be > 3. ");
	if (d.getName().size() < 3)
		errors.push_back("Dog name  must be > 3. ");
	if (d.getImageLink().size() < 6)
		errors.push_back("Image link must be > 6. ");
	if (d.getAge() > 20)
		errors.push_back("Dogs age is invalid");

	if (d.getImageLink().find("www") != 0)
		errors.push_back("The image link must start with <www>");
	
	if (errors.size() > 0)
		throw DogException(errors);
}
