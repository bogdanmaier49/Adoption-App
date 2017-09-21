#include "DogRepositoryController.h"


DogRepository* getDogsWithBreed(DogRepository* repo, std::string breed)
{
	if (repo == nullptr)
		return nullptr;

	DogRepository* result = new DogRepository();

	for (int i = 0; i < repo->getSize(); i++)
		if (repo->get(i).getBreed() == breed)
			result->add(repo->get(i));

	return result;
}

DogRepository* getDogsWithAgeLessThan(DogRepository* repo, unsigned int age)
{
	if (repo == nullptr)
		return nullptr;

	DogRepository* result = new DogRepository();

	for (int i = 0; i < repo->getSize(); i++)
		if (repo->get(i).getAge() < age)
			result->add(repo->get(i));

	return result;
}