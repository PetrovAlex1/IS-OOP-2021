#pragma once
#include <iostream>
#include "Jedi.h"
#include "Stormtrooper.h"

int ParseCharToInt2(char* text)
{
	int number = 0;
	int d = 10;

	for (int i = 0; text[i] != '\0'; i++)
	{
		number = number * d + text[i] - 48;
	}

	return number;
}

int CountSymbols4(char* text)
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

bool StrCmp4(char* text1, const char* text2)
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

bool StrCmp4(const char* text1, const char* text2)
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

template<typename P>

class BattleShip
{
private:
	double speed;
	int countCannons;
	bool couldMakeHyperJump;
	double size;
	P pilot;

public:

	BattleShip()
	{
		this->speed = 0.0;
		this->countCannons = 0;
		this->couldMakeHyperJump = false;
		this->size = 0.0;
	}

	BattleShip(const BattleShip& otherBattleShip)
	{
		this->speed = otherBattleShip.speed;
		this->countCannons = otherBattleShip.countCannons;
		this->couldMakeHyperJump = otherBattleShip.couldMakeHyperJump;
		this->size = otherBattleShip.size;
	}

	BattleShip& operator=(const BattleShip& otherBattleShip)
	{
		/*if (this != &otherBattleShip)
		{
			this->speed = 0.0;
			this->countCannons = 0;
			this->couldMakeHyperJump = false;
			this->size = 0.0;
		}*/

		this->speed = otherBattleShip.speed;
		this->countCannons = otherBattleShip.countCannons;
		this->couldMakeHyperJump = otherBattleShip.couldMakeHyperJump;
		this->size = otherBattleShip.size;
	}

	BattleShip(const double _speed, const int _countCannons, const bool _couldMakeHyperJump, const double _size, const P _pilot)
	{
		this->speed = _speed;
		this->countCannons = _countCannons;
		this->couldMakeHyperJump = _couldMakeHyperJump;
		this->size = _size;
		this->pilot = _pilot;
	}

	void Print()
	{
		std::cout << "Battle ship with speed " << this->speed
			<< " with " << this->countCannons << " connons ";

		if (this->couldMakeHyperJump)
		{
			std::cout << "and could make Hyper Jump ";
		}
		else
		{
			std::cout << "and could not make Hyper Jump";
		}

		std::cout << " with size " << this->size
			<< "and pilot" << this->pilot;
	}

	void SetSpeed(double _speed)
	{
		this->speed = _speed;
	}

	void SetCountCannons(int _countCannons)
	{
		this->countCannons = _countCannons;
	}

	void SetCouldMakeHyperJump(bool _couldMakeHyperJump)
	{
		this->couldMakeHyperJump = _couldMakeHyperJump;
	}

	void SetSize(double _size)
	{
		this->size = _size;
	}

	void SetPilot(P _pilot)
	{
		if (!StrCmp4(typeid(_pilot).name(), "class Jedi") && !StrCmp4(typeid(_pilot).name(), "class Stormtrooper"))
		{
			std::cerr << "Invalid type!" << std::endl;

			std::cin >> _pilot;
			SetPilot(_pilot);
		}

		this->pilot = _pilot;
	}

	double GetSpeed() const
	{
		return this->speed;
	}

	int GetCountCannons() const
	{
		return this->countCannons;
	}

	bool GetCouldMakeHyperJump() const
	{
		return this->couldMakeHyperJump;
	}

	double GetSize() const
	{
		return this->size;
	}

	P GetPilot() const
	{
		return this->pilot;
	}

	friend std::ostream& operator<<(std::ostream& out, const BattleShip& battleShip)
	{
		out << "Battle ship with speed " << battleShip.GetSpeed()
			<< " with " << battleShip.GetCountCannons() << " connons ";

		if (battleShip.GetCouldMakeHyperJump())
		{
			out << "and could make Hyper Jump ";
		}
		else
		{
			out << "and could not make Hyper Jump ";
		}

		out << " with size " << battleShip.GetSize()
			<< " and pilot " << std::endl << battleShip.GetPilot();

		return out;
	}

	friend std::istream& operator>>(std::istream& in, BattleShip& battleShip)
	{
		std::cout << "Enter speed ";
		double speed;
		in >> speed;
		battleShip.SetSpeed(speed);

		std::cout << "Enter count cannons: ";
		int countCannons;
		in >> countCannons;
		battleShip.SetCountCannons(countCannons);

		std::cout << "Enter whether could make a Hyper Jump: ";
		char couldMakeHyperJump[5];
		in >> couldMakeHyperJump;

		if (StrCmp4(couldMakeHyperJump, "true"))
		{
			battleShip.SetCouldMakeHyperJump(true);
		}
		else
		{
			battleShip.SetCouldMakeHyperJump(false);
		}

		std::cout << "Enter the information about the pilot: " << std::endl;
		P pilot;
		in >> pilot;
		battleShip.SetPilot(pilot);

		return in;
	}

	void ReadFromFile(const char* fileName, int& position)
	{
		std::ifstream input;
		input.open(fileName);
		char buffer[64];
		int i = 0;
		input.seekg(position, std::ios::cur);

		while (input.getline(buffer, 64, '\n'))
		{
			if (i == 5 && i > 0)
			{
				break;
			}

			i++;
			position += CountSymbols4(buffer) + 2;

			if (i == 1)
			{
				double num = atof(buffer);
				this->SetSpeed(num);
			}
			else if (i == 2)
			{
				this->SetCountCannons(ParseCharToInt2(buffer));
			}
			else if (i == 3)
			{
				if (StrCmp4(buffer, "true"))
				{
					this->SetCouldMakeHyperJump(true);
				}
				else
				{
					this->SetCouldMakeHyperJump(false);
				}
			}
			else if (i == 4)
			{
				double num = atof(buffer);
				this->SetSize(num);
			}
		}

		position += 2;
		input.close();
	}

	/*void WriteOnFileForBattleShip(const char* fileName)
	{
		std::ofstream myFile(fileName, std::ios::app);

		myFile << this->GetSpeed() << std::endl;
		myFile << this->GetCountCannons() << std::endl;
		myFile << this->GetCouldMakeHyperJump() << std::endl;
		myFile << this->GetSize() << std::endl;
		myFile << std::endl;

		myFile.close();
	}*/
};