#pragma once

#include "DogRepository.h"
#include "Dog.h"
#include <string>

DogRepository* getDogsWithBreed(DogRepository* repo, std::string breed);
DogRepository* getDogsWithAgeLessThan(DogRepository* repo, unsigned int age);