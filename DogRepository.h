#pragma once

#include "Dog.h"
#include <vector>

class DogRepository
{
private:

	std::vector<Dog>* vect;

public:
	DogRepository();
	~DogRepository();

	void add(Dog d);
	bool update(Dog toUpdate, Dog newDog);
	bool remove(Dog d);
	bool remove(unsigned int index);
	Dog get(unsigned int index);
	void set(unsigned int index, Dog d);
	bool exits(Dog d);

	inline std::vector<Dog>* getDogArray() const { return this->vect; }
	inline unsigned int getSize() const { return this->vect->size(); }

	int find(Dog d);
};

