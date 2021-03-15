#include "Planet.h"
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

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

Planet::Planet(const char* otherName, const char* otherPlanetSystem, const char* otherRepublic)
{
	this->SetName(otherName);
	this->SetPlanetSystem(otherPlanetSystem);
	this->SetRepublic(otherRepublic);
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
	if (this->name == nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Planet::SetPlanetSystem(const char* _planetSystem)
{
	if (this->planetSystem == nullptr)
	{
		delete[] this->planetSystem;
	}

	this->planetSystem = new char[strlen(_planetSystem) + 1];
	strcpy(this->planetSystem, _planetSystem);
}

void Planet::SetRepublic(const char* _republic)
{
	if (this->republic == nullptr)
	{
		delete[] this->republic;
	}

	this->republic = new char[strlen(_republic) + 1];
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
