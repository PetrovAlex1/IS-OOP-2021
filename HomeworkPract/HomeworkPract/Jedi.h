#pragma once
#include <iostream>
#include "Planet.h"

enum class JediRank
{
	Padawan,
	Master,
	GrandMaster,
	Knight
};

class Jedi
{
private:
	char* name;
	JediRank rank;
	double midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;
public:

	Jedi();

	Jedi(const Jedi& otherJedi);

	Jedi& operator=(const Jedi& otherJedi);

	Jedi(const char* _name, const JediRank _rank, const double& _midichlorian, const Planet& _planet, const char* _spicies, const char* _militaryRank);

	~Jedi();

	void Print();

	void SetName(const char* _name);

	void SetRank(const JediRank _rank);

	void SetMidichlorian(const double _midichlorian);

	void SetPlanet(const Planet _planet);

	void SetSpicies(const char* _spicies);

	void SetMilitaryRank(const char* _militaryRank);

	char* GetName() const;

	JediRank GetRank() const;

	double GetMidichlorian() const;

	Planet GetPlanet() const;

	char* GetSpicies() const;

	char* GetMilitaryRank() const;

	friend std::ostream& operator<<(std::ostream& out, const Jedi& jedi);

	friend std::istream& operator>>(std::istream& in, Jedi& jedi);

	void ReadFromFile(const char* fileName, int& positions);

	void WriteOnFileJedi(const char* fileName);
};