#include "Stormtrooper.h"
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

char* EnumTocharArray(TrooperRank rank, char* rankType)
{
	if (rank == TrooperRank::SquadLeader)
	{
		strcpy(rankType, "SquadLeader");
		return rankType;
	}
	else if (rank == TrooperRank::RegimentCommander)
	{
		strcpy(rankType, "RegimentCommander");
		return rankType;
	}
	else if (rank == TrooperRank::PlatoonLeader)
	{
		strcpy(rankType, "PlatoonLeader");
		return rankType;
	}
	else if (rank == TrooperRank::GeneralOfLegion)
	{
		strcpy(rankType, "GeneralOfLegion");
		return rankType;
	}
	else if (rank == TrooperRank::CompanyLeader)
	{
		strcpy(rankType, "CompanyLeader");
		return rankType;
	}
	else if (rank == TrooperRank::BattalionCommander)
	{
		strcpy(rankType, "BattalionCommander");
		return rankType;
	}
	else
	{
		strcpy(rankType, "Trooper");
		return rankType;
	}

}

Stormtrooper::Stormtrooper()
{
	this->id = nullptr;
	this->rank = TrooperRank::Trooper;
	this->type = nullptr;
}

Stormtrooper::Stormtrooper(const Stormtrooper& other)
{
	this->id = new char[strlen(other.id) + 1];
	strcpy(this->id, other.id);
	this->rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	strcpy(this->type, other.type);
	this->planet = other.planet;
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other)
{
	if (this != &other)
	{
		delete[] id;
		delete[] type;
	}

	this->id = new char[strlen(other.id) + 1];
	strcpy(this->id, other.id);
	this->rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	strcpy(this->type, other.type);
	this->planet = other.planet;

	return *this;
}

Stormtrooper::Stormtrooper(const char* _id, const TrooperRank _rank, const char* _type, const Planet& _planet)
{
	this->SetID(_id);
	this->SetRank(_rank);
	this->SetType(_type);
	this->SetPlanet(_planet);
}

Stormtrooper::~Stormtrooper()
{
	delete[] this->id;
	delete[] this->type;
}

void Stormtrooper::Print()
{
	char* rankType = new char[32];
	rankType = EnumTocharArray(this->rank, rankType);
	std::cout << "Stormtrooper with id: " << this->id << " rank: " << rankType << " type: " << this->type << " from " << this->planet.GetName() << std::endl;

	delete[] rankType;
}

void Stormtrooper::SetID(const char* _id)
{
	if (this->id == nullptr)
	{
		delete[] this->id;
	}

	this->id = new char[strlen(_id) + 1];
	strcpy(this->id, _id);
}

void Stormtrooper::SetRank(const TrooperRank _rank)
{
	this->rank = _rank;
}

void Stormtrooper::SetType(const char* _type)
{
	if (this->type == nullptr)
	{
		delete[] this->type;
	}

	this->type = new char[strlen(_type) + 1];
	strcpy(this->type, _type);
}

void Stormtrooper::SetPlanet(const Planet& otherPlanet)
{
	this->planet = otherPlanet;
}

char* Stormtrooper::GetID()
{
	return this->id;
}

TrooperRank Stormtrooper::GetRank()
{
	return this->rank;
}

char* Stormtrooper::GetType()
{
	return this->type;
}

Planet Stormtrooper::GetPlanet()
{
	return this->planet;
}