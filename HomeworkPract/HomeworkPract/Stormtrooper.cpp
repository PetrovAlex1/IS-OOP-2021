#include "Stormtrooper.hpp"

void CopyText3(char* firstText, const char* secondText)
{
	int i;

	for (i = 0; i < strlen(secondText); i++)
	{
		firstText[i] = secondText[i];
	}

	firstText[i] = '\0';
}

char* EnumTocharArray(TrooperRank rank)
{

	char rankType[16];

	if (rank == TrooperRank::SquadLeader)
	{
		CopyText3(rankType, "SquadLeader");
		return rankType;
	}
	else if (rank == TrooperRank::RegimentCommander)
	{
		CopyText3(rankType, "RegimentCommander");
		return rankType;
	}
	else if (rank == TrooperRank::PlatoonLeader)
	{
		CopyText3(rankType, "PlatoonLeader");
		return rankType;
	}
	else if (rank == TrooperRank::GeneralOfLegion)
	{
		CopyText3(rankType, "GeneralOfLegion");
		return rankType;
	}
	else if (rank == TrooperRank::CompanyLeader)
	{
		CopyText3(rankType, "CompanyLeader");
		return rankType;
	}
	else if (rank == TrooperRank::BattalionCommander)
	{
		CopyText3(rankType, "BattalionCommander");
		return rankType;
	}
	else
	{
		CopyText3(rankType, "Trooper");
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
	CopyText3(this->id, other.id);
	this->rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	CopyText3(this->type, other.type);
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
	CopyText3(this->id, other.id);
	this->rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	CopyText3(this->type, other.type);
	this->planet = other.planet;

	return *this;
}

Stormtrooper::Stormtrooper(const char* _id, const TrooperRank _rank, const char* _type, const Planet& _planet)
{
	CopyText3(this->id, _id);
	this->rank = _rank;
	CopyText3(this->type, _type);
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

void Stormtrooper::SetID(const char* _id)
{
	CopyText3(this->id, _id);
}

void Stormtrooper::SetRank(const TrooperRank _rank)
{
	this->rank = _rank;
}

void Stormtrooper::SetType(const char* _type)
{
	CopyText3(this->type, _type);
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
