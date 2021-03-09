#define _CRT_SECURE_NO_WARNINGS
#include "Jedi.hpp"

char* EnumTocharArray(JediRank rank)
{
	char rankType[16];

	if (rank == JediRank::GrandMaster)
	{
		strcpy_s(rankType, "GrandMaster");
		return rankType;
	}
	else if (rank == JediRank::Master)
	{
		strcpy_s(rankType, "Master");
		return rankType;
	}
	else
	{
		strcpy_s(rankType, "Padawan");
		return rankType;
	}
}

Jedi::Jedi()
{
	this->name = nullptr;
	this->rank = JediRank::Padawan;
	this->midichlorian = 0.0;
	this->spicies = nullptr;
	this->militaryRank = nullptr;
}

Jedi::Jedi(const Jedi& otherJedi)
{
	this->name = new char[strlen(otherJedi.name) + 1];
	strcpy(this->name, otherJedi.name);
	this->rank = otherJedi.rank;
	this->planet = otherJedi.planet;
	this->spicies = new char[strlen(otherJedi.spicies) + 1];
	strcpy(this->spicies, otherJedi.spicies);
	this->militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
	strcpy(this->militaryRank, otherJedi.militaryRank);
}

Jedi& Jedi::operator=(const Jedi& otherJedi)
{
	if (this != &otherJedi)
	{
		delete[] name;
		midichlorian = 0.0;
		delete[] spicies;
		delete[] spicies;
		delete[] militaryRank;
	}

	this->name = new char[strlen(otherJedi.name) + 1];
	strcpy(this->name, otherJedi.name);
	this->rank = otherJedi.rank;
	this->planet = otherJedi.planet;
	this->spicies = new char[strlen(otherJedi.spicies) + 1];
	strcpy(this->spicies, otherJedi.spicies);
	this->militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
	strcpy(this->militaryRank, otherJedi.militaryRank);

	return *this;
}

Jedi::Jedi(char* _name, JediRank _rank, float _midichlorian, Planet _planet, char* _spicies, char* _militaryRank)
{
	strcpy(this->name, _name);
	this->rank = _rank;
	this->midichlorian = _midichlorian;
	this->planet = _planet;
	strcpy(this->spicies, _spicies);
	strcpy(this->militaryRank, _militaryRank);
}

Jedi::~Jedi()
{
	delete[] name;
	midichlorian = 0.0;
	delete[] spicies;
	delete[] militaryRank;
}

void Jedi::Print()
{
	std::cout << "Jedi " << this->name <<
		"with rank: " << EnumTocharArray(this->rank) <<
		" with midichlorian: " << this->midichlorian <<
		" from " << this->planet.GetName() <<
		"with spicies: " << this->spicies <<
		" with militaryRank: " << this->militaryRank << std::endl;
}

void Jedi::SetName(char* _name)
{
	strcpy(this->name, _name);
}

void Jedi::SetRank(JediRank _rank)
{
	this->rank = _rank;
}

void Jedi::SetMidichlorian(float _midichlorian)
{
	this->midichlorian = _midichlorian;
}

void Jedi::SetPlanet(Planet _planet)
{
	this->planet = _planet;
}

void Jedi::SetSpicies(char* _spicies)
{
	this->spicies = _spicies;
}

void Jedi::SetMilitaryRank(char* _militaryRank)
{
	this->militaryRank = _militaryRank;
}

char* Jedi::GetName()
{
	return this->name;
}

JediRank Jedi::GetRank()
{
	return this->rank;
}

float Jedi::GetMidichlorian()
{
	return this->midichlorian;
}

Planet Jedi::GetPlanet()
{
	return this->planet;
}

char* Jedi::GetSpicies()
{
	return this->spicies;
}

char* Jedi::GetMilitaryRank()
{
	return this->militaryRank;
}
