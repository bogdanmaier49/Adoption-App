#include "Tests.h"

void TestDogRepository()
{
	DogRepository* repo = new DogRepository();

	for (int i=0; i<1000; i++)
		repo->add(Dog(
			"breed" + std::to_string(i),
			"name" + std::to_string(i),
			"www.link" + std::to_string(i) + ".com",
			8
			));

	assert(repo->getSize() == 1000);

	for (int i = 0; i < 1000; i++)
	{
		Dog d = repo->get(i);
		assert(d.getBreed() == "breed" + std::to_string(i));
		assert(d.getName() == "name" + std::to_string(i));
		assert(d.getImageLink() == "www.link" + std::to_string(i) + ".com");
		assert(d.getAge() == 8);
	}

	repo->remove(9);
	repo->remove(10);
	repo->remove(11);
	repo->remove(15);

	assert(repo->getSize() == 996);

	Dog d9 = repo->get(9);

	assert(d9.getBreed() == "breed" + std::to_string(12));
	assert(d9.getName() == "name" + std::to_string(12));
	assert(d9.getImageLink() == "www.link" + std::to_string(12) + ".com");
	assert(d9.getAge() == 8);


	delete repo;
}

void TestDogRepositoryController()
{
	DogRepository* repo = new DogRepository();

	for (int i = 0; i<1000; i++)
		repo->add(Dog(
			"breed" + std::to_string(i),
			"name" + std::to_string(i),
			"www.link" + std::to_string(i) + ".com",
			i
		));

	assert(repo->getSize() == 1000);

	for (int i = 0; i < 1000; i++)
	{
		Dog d = repo->get(i);
		assert(d.getBreed() == "breed" + std::to_string(i));
		assert(d.getName() == "name" + std::to_string(i));
		assert(d.getImageLink() == "www.link" + std::to_string(i) + ".com");
		assert(d.getAge() == i);
	}

	DogRepository* res = getDogsWithAgeLessThan(repo, 10);
	assert(res->getSize() == 10);
	delete res;

	repo->add(Dog("special", "name", "www.link.com", 10));
	repo->add(Dog("special", "name2", "www.link.com", 10));
	repo->add(Dog("special", "name1", "www.link.com", 10));
	repo->add(Dog("special", "name3", "www.link.com", 10));
	repo->add(Dog("special", "name5", "www.link.com", 10));
	repo->add(Dog("special", "name3", "www.link.com", 10));
	repo->add(Dog("special", "name2", "www.link.com", 10));

	DogRepository* res1 = getDogsWithBreed(repo, "special");
	assert(res1->getSize() == 7);
	delete res1;

	delete repo;
}
