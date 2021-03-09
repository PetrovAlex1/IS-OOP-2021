#define _CRT_SECURE_NO_WARNINGS
#include "Planet.hpp"

Planet::Planet()
{
	this->name = nullptr;
	this->planetSystem = nullptr;
	this->republic = nullptr;
}

Planet::Planet(const Planet& otherPlanet)
{
	this->name = new char[strlen(otherPlanet.name) + 1];
	strcpy(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	strcpy(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy(this->republic, otherPlanet.republic);
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
	strcpy(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	strcpy(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy(this->republic, otherPlanet.republic);

	return *this;
}

Planet::Planet(char* otherName, char* otherPlanetSystem, char* otherRepublic)
{
	strcpy(this->name, otherName);
	strcpy(this->planetSystem, otherPlanetSystem);
	strcpy(this->republic, otherRepublic);
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

void Planet::SetName(char* _name)
{
	strcpy(this->name, _name);
}

void Planet::SetPlanetSystem(char* _planetSystem)
{
	strcpy(this->planetSystem, _planetSystem);
}

void Planet::SetRepublic(char* _republic)
{
	strcpy(this->republic, _republic);
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
