#define _CRT_SECURE_NO_WARNINGS
#include "Stormtrooper.hpp"

char* EnumTocharArray(TrooperRank rank)
{

	char rankType[16];

	if (rank == TrooperRank::SquadLeader)
	{
		strcpy_s(rankType, "SquadLeader");
		return rankType;
	}
	else if (rank == TrooperRank::RegimentCommander)
	{
		strcpy_s(rankType, "RegimentCommander");
		return rankType;
	}
	else if (rank == TrooperRank::PlatoonLeader)
	{
		strcpy_s(rankType, "PlatoonLeader");
		return rankType;
	}
	else if (rank == TrooperRank::GeneralOfLegion)
	{
		strcpy_s(rankType, "GeneralOfLegion");
		return rankType;
	}
	else if (rank == TrooperRank::CompanyLeader)
	{
		strcpy_s(rankType, "CompanyLeader");
		return rankType;
	}
	else if (rank == TrooperRank::BattalionCommander)
	{
		strcpy_s(rankType, "BattalionCommander");
		return rankType;
	}
	else
	{
		strcpy_s(rankType, "Trooper");
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

Stormtrooper::Stormtrooper(char* _id, TrooperRank _rank, char* _type, Planet& _planet)
{
	strcpy(this->id, _id);
	this->rank = _rank;
	strcpy(this->type, _type);
	this->planet = _planet;
}

Stormtrooper::~Stormtrooper()
{
	delete[] this->id;
	delete[] this->type;
}

void Stormtrooper::Print()
{
	std::cout << "Stormtrooper with id: " << this->id << " rank: " << EnumTocharArray(this->rank) << " type: " << this->type << " from " << this->planet.GetName() << std::endl;
}

void Stormtrooper::SetID(char* _id)
{
	strcpy(this->id, _id);
}

void Stormtrooper::SetRank(TrooperRank _rank)
{
	this->rank = _rank;
}

void Stormtrooper::SetType(char* _type)
{
	strcpy(this->type, _type);
}

void Stormtrooper::SetPlanet(Planet& otherPlanet)
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
