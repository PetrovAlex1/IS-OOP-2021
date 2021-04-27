#include "Stormtrooper.h"
#include "CommonFunctions.h"
#include <fstream>
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

TrooperRank CharArrayToEnumTrooper(char* rank)
{
	if (rank[0] >= 97 && rank[0] <= 122)
	{
		rank[0] -= 'a' - 'A';
	}

	if (StrCmp(rank, "SquadLeader"))
	{
		return TrooperRank::SquadLeader;
	}
	else if (StrCmp(rank, "RegimentCommander"))
	{
		return TrooperRank::RegimentCommander;
	}
	else if (StrCmp(rank, "Commander"))
	{
		return TrooperRank::Commander;
	}
	else if (StrCmp(rank, "Enlisted"))
	{
		return TrooperRank::Enlisted;
	}
	else if (StrCmp(rank, "Sergeant"))
	{
		return TrooperRank::Sergeant;
	}
	else if (StrCmp(rank, "PlatoonLeader"))
	{
		return TrooperRank::PlatoonLeader;
	}
	else if (StrCmp(rank, "GeneralOfLegion"))
	{
		return TrooperRank::GeneralOfLegion;
	}
	else if (StrCmp(rank, "CompanyLeader"))
	{
		return TrooperRank::CompanyLeader;
	}
	else if (StrCmp(rank, "BattalionCommander"))
	{
		return TrooperRank::BattalionCommander;
	}
	else
	{
		return TrooperRank::Trooper;
	}
}

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
	else if (rank == TrooperRank::Commander)
	{
		strcpy(rankType, "Commander");
		return rankType;
	}
	else if (rank == TrooperRank::Enlisted)
	{
		strcpy(rankType, "Enlisted");
		return rankType;
	}
	else if (rank == TrooperRank::Sergeant)
	{
		strcpy(rankType, "Sergeant");
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
		this->id = new char[strlen(other.id) + 1];
		strcpy(this->id, other.id);
		this->rank = other.rank;
		this->type = new char[strlen(other.type) + 1];
		strcpy(this->type, other.type);
		this->planet = other.planet;
	}

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
	rankType = EnumTocharArray(this->GetRank(), rankType);
	std::cout << "Stormtrooper with id: " << this->GetID() << " rank: " << rankType << " type: " << this->GetType() << " from " << this->planet.GetName() << std::endl;

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

char* Stormtrooper::GetID() const
{
	return this->id;
}

TrooperRank Stormtrooper::GetRank() const
{
	return this->rank;
}

char* Stormtrooper::GetType() const
{
	return this->type;
}

Planet Stormtrooper::GetPlanet() const
{
	return this->planet;
}

std::ostream& operator<<(std::ostream& out, const Stormtrooper& trooper)
{
	out << "Stormtrooper with id: " << trooper.GetID()
		<< " type: " << trooper.GetType()
		<< " from " << std::endl << trooper.GetPlanet().GetName()
		<< " rank: ";

	if (trooper.GetRank() == TrooperRank::SquadLeader)
	{
		out << "SquadLeader" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::RegimentCommander)
	{
		out << "RegimentCommander" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::Commander)
	{
		out << "Commander" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::Enlisted)
	{
		out << "Enlisted" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::Sergeant)
	{
		out << "Sergeant" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::PlatoonLeader)
	{
		out << "PlatoonLeader" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::GeneralOfLegion)
	{
		out << "GeneralOfLegion" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::CompanyLeader)
	{
		out << "CompanyLeader" << std::endl;
	}
	else if (trooper.GetRank() == TrooperRank::BattalionCommander)
	{
		out << "BattalionCommander" << std::endl;
	}
	else
	{
		out << "Trooper" << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Stormtrooper& trooper)
{
	std::cout << "Enter trooper id: ";
	char id[8];
	in >> id;
	trooper.SetID(id);

	std::cout << "Enter rank: ";
	char rank[32];
	in >> rank;
	trooper.SetRank(CharArrayToEnumTrooper(rank));

	std::cout << "Enter type: ";
	char type[32];
	in >> type;
	trooper.SetType(type);

	std::cout << "Enter information about the planet: " << std::endl;
	Planet planet;
	in >> planet;
	trooper.SetPlanet(planet);

	return in;
}

void Stormtrooper::ReadFromFile(const char* fileName, int& position)
{
	std::ifstream input;
	input.open(fileName);
	char buffer[64];
	int i = 0;
	input.seekg(position, std::ios::cur);

	while (input.getline(buffer, 64, '\n'))
	{
		if (i == 4 && i > 0)
		{
			break;
		}

		i++;
		position += CountSymbols(buffer) + 2;

		if (i == 1)
		{
			this->SetID(buffer);
		}
		else if (i == 2)
		{
			this->SetRank(CharArrayToEnumTrooper(buffer));
		}
		else if (i == 3)
		{
			this->SetType(buffer);
		}
		else
		{
			this->planet.SetName(buffer);
		}
	}

	position += 2;
	input.close();
}

void Stormtrooper::WriteOnFileTrooper(const char* fileName)
{
	std::ofstream myFile(fileName, std::ios::app);

	myFile << this->GetID() << std::endl;

	char* rankType = new char[32];
	rankType = EnumTocharArray(this->GetRank(), rankType);
	myFile << rankType << std::endl;

	myFile << this->GetType() << std::endl;
	myFile << this->GetPlanet().GetName() << std::endl;
	myFile << std::endl;

	delete[] rankType;
	myFile.close();
}