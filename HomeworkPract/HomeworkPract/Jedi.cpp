#include "Jedi.h"
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

char* EnumTocharArray(JediRank rank, char* rankType)
{
	if (rank == JediRank::GrandMaster)
	{
		strcpy(rankType, "GrandMaster");
		return rankType;
	}
	else if (rank == JediRank::Master)
	{
		strcpy(rankType, "Master");
		return rankType;
	}
	else
	{
		strcpy(rankType, "Padawan");
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

Jedi::Jedi(const char* _name, const JediRank _rank, const float _midichlorian, const Planet& _planet, const char* _spicies, const char* _militaryRank)
{
	this->SetName(_name);
	this->SetRank(_rank);
	this->SetMidichlorian(_midichlorian);
	this->SetPlanet(_planet);
	this->SetSpicies(_spicies);
	this->SetMilitaryRank(_militaryRank);
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
	char* rankType = new char[32];
	rankType = EnumTocharArray(this->rank, rankType);

	std::cout << "Jedi " << this->name <<
		"with rank: " << rankType <<
		" with midichlorian: " << this->midichlorian <<
		" from " << this->planet.GetName() <<
		" with spicies: " << this->spicies <<
		" with militaryRank: " << this->militaryRank << std::endl;

	delete[] rankType;
}

void Jedi::SetName(const char* _name)
{
	if (this->name == nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Jedi::SetRank(const JediRank _rank)
{
	this->rank = _rank;
}

void Jedi::SetMidichlorian(const float _midichlorian)
{
	this->midichlorian = _midichlorian;
}

void Jedi::SetPlanet(const Planet _planet)
{
	this->planet = _planet;
}

void Jedi::SetSpicies(const char* _spicies)
{
	if (this->spicies == nullptr)
	{
		delete[] this->spicies;
	}

	this->spicies = new char[strlen(_spicies) + 1];
	strcpy(this->spicies, _spicies);
}

void Jedi::SetMilitaryRank(const char* _militaryRank)
{
	if (this->militaryRank == nullptr)
	{
		delete[] this->militaryRank;
	}

	this->militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy(this->militaryRank, _militaryRank);
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