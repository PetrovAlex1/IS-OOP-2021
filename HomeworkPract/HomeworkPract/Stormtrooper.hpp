#pragma once
#include <iostream>
#include "Planet.hpp"

enum TrooperRank
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

	Stormtrooper(char* _id, TrooperRank _rank, char* _type, Planet& _planet);

	~Stormtrooper();

	void Print();

	void SetID(char* _id);

	void SetRank(TrooperRank _rank);

	void SetType(char* _type);

	void SetPlanet(Planet& otherPlanet);

	char* GetID();

	TrooperRank GetRank();

	char* GetType();

	Planet GetPlanet();
};