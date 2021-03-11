#pragma once
#include <iostream>
#include "Planet.hpp"

enum class JediRank
{
	Padawan,
	Master,
	GrandMaster
};

void CopyText1(char* firstText, const char* secondText);

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

	Jedi(const char* _name, const JediRank _rank, const float _midichlorian, const Planet _planet, const char* _spicies, const char* _militaryRank);

	~Jedi();

	void Print();

	void SetName(const char* _name);

	void SetRank(const JediRank _rank);

	void SetMidichlorian(const float _midichlorian);

	void SetPlanet(const Planet _planet);

	void SetSpicies(const char* _spicies);

	void SetMilitaryRank(const char* _militaryRank);

	char* GetName();

	JediRank GetRank();

	float GetMidichlorian();

	Planet GetPlanet();

	char* GetSpicies();

	char* GetMilitaryRank();
};