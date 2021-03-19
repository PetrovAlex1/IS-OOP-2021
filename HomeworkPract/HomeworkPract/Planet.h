#pragma once
#include <iostream>

class Planet
{
private:
	char* name;
	char* planetSystem;
	char* republic;
public:

	Planet();

	Planet(const Planet& otherPlanet);

	Planet& operator=(const Planet& otherPlanet);

	Planet(const char* otherName, const char* otherPlanetSystem, const char* otherRepublic);

	~Planet();

	void Print();

	void SetName(const char* _name);

	void SetPlanetSystem(const char* _planetSystem);

	void SetRepublic(const char* _republic);

	char* GetName();

	char* GetPlanetSystem();

	char* GetRepublic();
};