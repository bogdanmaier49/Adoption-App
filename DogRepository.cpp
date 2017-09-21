#include "DogRepository.h"



DogRepository::DogRepository()
{
	this->vect = new std::vector<Dog>();
}


DogRepository::~DogRepository()
{
	delete this->vect;
}

void DogRepository::add(Dog d)
{
	this->vect->push_back(d);
}

bool DogRepository::update(Dog toUpdate, Dog newDog)
{
	if (this->exits(toUpdate) == false)
		return false;

	this->vect->at(this->find(toUpdate)) = newDog;

	return true;
}

bool DogRepository::remove(Dog d)
{
	this->vect->erase(this->vect->begin() + this->find(d));
	return true;
}

bool DogRepository::remove(unsigned int index)
{
	this->vect->erase(this->vect->begin() + index);
	return true;
}

Dog DogRepository::get(unsigned int index)
{
	return this->vect->at(index);
}

void DogRepository::set(unsigned int index, Dog d)
{
	this->vect->at(index) = d;

}

bool DogRepository::exits(Dog d)
{
	unsigned int result = this->find(d);

	if (result == -1)
		return false;

	return true;
}

int DogRepository::find(Dog d)
{
	for (int i = 0; i < this->vect->size(); i++)
		if (this->vect->at(i) == d)
			return i;

	return -1;
}
