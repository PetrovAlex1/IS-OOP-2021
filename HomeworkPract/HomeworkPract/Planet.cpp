#include "Planet.hpp"

void CopyText2(char* firstText, const char* secondText)
{
	int i;

	for (i = 0; i < strlen(secondText); i++)
	{
		firstText[i] = secondText[i];
	}

	firstText[i] = '\0';
}

Planet::Planet()
{
	this->name = nullptr;
	this->planetSystem = nullptr;
	this->republic = nullptr;
}

Planet::Planet(const Planet& otherPlanet)
{
	this->name = new char[strlen(otherPlanet.name) + 1];
	CopyText2(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	CopyText2(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	CopyText2(this->republic, otherPlanet.republic);
}

Planet& Planet::operator=(const Planet& otherPlanet)
{
	if (this != &otherPlanet)
	{
		delete[] name;
		delete[] planetSystem;
		delete[] republic;
	}

	this->name = new char[strlen(otherPlanet.name) + 1];
	CopyText2(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	CopyText2(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	CopyText2(this->republic, otherPlanet.republic);

	return *this;
}

Planet::Planet(const char* otherName, const char* otherPlanetSystem, const char* otherRepublic)
{
	CopyText2(this->name, otherName);
	CopyText2(this->planetSystem, otherPlanetSystem);
	CopyText2(this->republic, otherRepublic);
}

Planet::~Planet()
{
	delete[] this->name;
	delete[] this->planetSystem;
	delete[] this->republic;
}

void Planet::Print()
{
	std::cout << "Planet " << this->name << " from " << this->planetSystem << " belongs to republic " << this->republic << std::endl;
}

void Planet::SetName(const char* _name)
{
	CopyText2(this->name, _name);
}

void Planet::SetPlanetSystem(const char* _planetSystem)
{
	CopyText2(this->planetSystem, _planetSystem);
}

void Planet::SetRepublic(const char* _republic)
{
	CopyText2(this->republic, _republic);
}

char* Planet::GetName()
{
	return this->name;
}

char* Planet::GetPlanetSystem()
{
	return this->planetSystem;
}

char* Planet::GetRepublic()
{
	return this->republic;
}
