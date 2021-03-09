#pragma once
#include <iostream>
#include "Planet.hpp"

enum JediRank
{
	Padawan,
	Master,
	GrandMaster
};

char* EnumTocharArray(JediRank rank);

class Jedi
{
private:
	char* name;
	JediRank rank;
	float midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;
public:

	Jedi();

	Jedi(const Jedi& otherJedi);

	Jedi& operator=(const Jedi& otherJedi);

	Jedi(char* _name, JediRank _rank, float _midichlorian, Planet _planet, char* _spicies, char* _militaryRank);

	~Jedi();

	void Print();

	void SetName(char* _name);

	void SetRank(JediRank _rank);

	void SetMidichlorian(float _midichlorian);

	void SetPlanet(Planet _planet);

	void SetSpicies(char* _spicies);

	void SetMilitaryRank(char* _militaryRank);

	char* GetName();

	JediRank GetRank();

	float GetMidichlorian();

	Planet GetPlanet();

	char* GetSpicies();

	char* GetMilitaryRank();
};