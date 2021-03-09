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

	Planet(char* otherName, char* otherPlanetSystem, char* otherRepublic);

	~Planet();

	void Print();

	void SetName(char* _name);

	void SetPlanetSystem(char* _planetSystem);

	void SetRepublic(char* _republic);

	char* GetName();

	char* GetPlanetSystem();

	char* GetRepublic();
};
