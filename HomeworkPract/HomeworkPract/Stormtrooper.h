#pragma once
#include <iostream>
#include "Planet.h"

enum class TrooperRank
{
	Trooper,
	SquadLeader,
	PlatoonLeader,
	CompanyLeader,
	BattalionCommander,
	RegimentCommander,
	GeneralOfLegion
};

char* EnumTocharArray(TrooperRank rank);

class Stormtrooper
{
private:
	char* id;
	TrooperRank rank;
	char* type;
	Planet planet;
public:

	Stormtrooper();

	Stormtrooper(const Stormtrooper& other);

	Stormtrooper& operator=(const Stormtrooper& other);

	Stormtrooper(const char* _id, const TrooperRank _rank, const char* _type, const Planet& _planet);

	~Stormtrooper();

	void Print();

	void SetID(const char* _id);

	void SetRank(const TrooperRank _rank);

	void SetType(const char* _type);

	void SetPlanet(const Planet& otherPlanet);

	char* GetID();

	TrooperRank GetRank();

	char* GetType();

	Planet GetPlanet();
};