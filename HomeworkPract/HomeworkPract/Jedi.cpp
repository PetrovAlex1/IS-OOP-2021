#include "Jedi.h"
#include <fstream>
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

int ParseCharToInt1(char* text)
{
	int number = 0;
	int d = 10;

	for (int i = 0; text[i] != '\0'; i++)
	{
		number = number * d + text[i] - 48;
	}

	return number;
}

int CountSymbols3(char* text)
{
	int counter = 0;
	int i = 0;

	while (text[i] != '\0')
	{
		counter++;
		i++;
	}

	return counter;
}

bool StrCmp3(char* text1, const char* text2)
{
	int i = 0;

	while (text1[i] != '\0')
	{
		if (text1[i] != text2[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

JediRank CharArrayToEnumJedi(char* rank)
{
	if (rank[0] >= 97 && rank[0] <= 122)
	{
		rank[0] -= 'a' - 'A';
	}

	if (StrCmp3(rank, "Knight"))
	{
		return JediRank::Knight;
	}
	else if (StrCmp3(rank, "Master"))
	{
		return JediRank::Master;
	}
	else if (StrCmp3(rank, "GrandMaster"))
	{
		return JediRank::GrandMaster;
	}
	else if (StrCmp3(rank, "Padawan"))
	{
		return JediRank::Padawan;
	}
}

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
		this->name = new char[strlen(otherJedi.name) + 1];
		strcpy(this->name, otherJedi.name);
		this->rank = otherJedi.rank;
		this->planet = otherJedi.planet;
		this->spicies = new char[strlen(otherJedi.spicies) + 1];
		strcpy(this->spicies, otherJedi.spicies);
		this->militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
		strcpy(this->militaryRank, otherJedi.militaryRank);
	}

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
	delete[] this->name;
	this->midichlorian = 0.0;
	delete[] this->spicies;
	delete[] this->militaryRank;
}

void Jedi::Print()
{
	char* rankType = new char[32];
	rankType = EnumTocharArray(this->GetRank(), rankType);

	std::cout << "Jedi " << this->GetName() <<
		"with rank: " << rankType <<
		" with midichlorian: " << this->GetMidichlorian() <<
		" from " << this->GetPlanet().GetName() <<
		" with spicies: " << this->GetSpicies() <<
		" with militaryRank: " << this->GetMilitaryRank() << std::endl;

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

char* Jedi::GetName() const
{
	return this->name;
}

JediRank Jedi::GetRank() const
{
	return this->rank;
}

float Jedi::GetMidichlorian() const
{
	return this->midichlorian;
}

Planet Jedi::GetPlanet() const
{
	return this->planet;
}

char* Jedi::GetSpicies() const
{
	return this->spicies;
}

char* Jedi::GetMilitaryRank() const
{
	return this->militaryRank;
}

std::ostream& operator<<(std::ostream& out, const Jedi& jedi)
{
	out << "Jedi " << jedi.GetName()
		<< " with midichlorian: " << jedi.GetMidichlorian()
		<< " from " << std::endl << jedi.GetPlanet().GetName()
		<< " with spicies: " << jedi.GetSpicies()
		<< " with militaryRank: " << jedi.GetMilitaryRank() << std::endl
		<< " with rank: ";

	if (jedi.GetRank() == JediRank::GrandMaster)
	{
		out << "GrandMaster" << std::endl;
	}
	else if (jedi.GetRank() == JediRank::Master)
	{
		out << "Master" << std::endl;
	}
	else if (jedi.GetRank() == JediRank::Knight)
	{
		out << "knight" << std::endl;
	}
	else
	{
		out << "Padawan" << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Jedi& jedi)
{
	std::cout << "Enter jedi name: ";
	char name[32];
	in >> name;
	jedi.SetName(name);

	std::cout << "Enter rank: ";
	char rank[32];
	in >> rank;
	jedi.SetRank(CharArrayToEnumJedi(rank));

	std::cout << "Enter midichlorian: ";
	float midichlorian;
	in >> midichlorian;
	jedi.SetMidichlorian(midichlorian);

	std::cout << "Enter the information about the planet: " << std::endl;
	Planet planet;
	in >> planet;
	jedi.SetPlanet(planet);

	std::cout << "Enter spicies: ";
	char spicies[32];
	in >> spicies;
	jedi.SetSpicies(spicies);

	std::cout << "Enter military rank: ";
	char militaryRank[32];
	in >> militaryRank;
	jedi.SetMilitaryRank(militaryRank);

	return in;
}

void Jedi::ReadFromFile(const char* fileName, int& position)
{
	std::ifstream input;
	input.open(fileName);
	char buffer[64];
	int i = 0;
	input.seekg(position, std::ios::cur);

	while (input.getline(buffer, 64, '\n'))
	{
		if (i == 6 && i > 0)
		{
			break;
		}

		i++;
		position += CountSymbols3(buffer) + 2;

		if (i == 1)
		{
			this->SetName(buffer);
		}
		else if (i == 2)
		{
			this->SetRank(CharArrayToEnumJedi(buffer));
		}
		else if (i == 3)
		{
			this->SetMidichlorian(ParseCharToInt1(buffer));
		}
		else if (i == 4)
		{
			this->planet.SetName(buffer);
		}
		else if (i == 5)
		{
			this->SetSpicies(buffer);
		}
		else
		{
			this->SetMilitaryRank(buffer);
		}
	}

	position += 2;
	input.close();
}

void Jedi::WriteOnFileJedi(const char* fileName)
{
	std::ofstream myFile(fileName, std::ios::app);

	myFile << this->GetName() << std::endl;

	char* rankType = new char[32];
	rankType = EnumTocharArray(this->GetRank(), rankType);
	myFile << rankType << std::endl;

	myFile << this->GetMidichlorian() << std::endl;
	myFile << this->GetPlanet().GetName() << std::endl;
	myFile << this->GetSpicies() << std::endl;
	myFile << this->GetMilitaryRank() << std::endl;
	myFile << std::endl;

	delete[] rankType;
	myFile.close();
}