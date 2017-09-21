#pragma once

#include <string>
#include <vector>

class Dog
{
private:
	std::string name;
	std::string breed;
	std::string image_link;
	unsigned int age;

public:
	Dog();
	Dog(std::string, std::string, std::string, unsigned int);

	/*
		Getters
	*/

	inline std::string getName() const { return this->name; }
	inline std::string getBreed() const { return this->breed; }
	inline std::string getImageLink() const { return this->image_link; }
	inline unsigned int getAge() const { return this->age; }

	/*
		Setters
	*/

	void setName(std::string newName);
	void setBreed(std::string newBreed);
	void setImageLink(std::string newImageLink);
	void setAge(unsigned int newAge);

	bool operator== (Dog other)
	{
		if (this->name == other.name &&
			this->breed == other.breed &&
			this->image_link == other.image_link &&
			this->age == other.age)
			return true;
		return false;
	}

	bool operator!= (Dog other)
	{
		if (*this == other)
			return false;
		return true;
	}

	void operator= (Dog other)
	{
		this->age = other.age;
		this->name = other.name;
		this->breed = other.breed;
		this->image_link = other.image_link;
	}



	std::string toString();
};

class DogException {

	std::vector<std::string> errors;

public:
	DogException(std::vector<std::string> errors) {
		this->errors = errors;
	}

	std::vector<std::string> get() { return this->errors; }

};

class DogValidator {

public:
	DogValidator() {}
	static void validate(const Dog & d);

};

#define NULL_DOG Dog()