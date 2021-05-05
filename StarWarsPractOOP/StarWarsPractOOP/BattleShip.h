#pragma once
#include <iostream>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "myVector.h"
#include "CommonFunctions.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

enum class Ammunition
{
	HeavyEquipment,
	MiddleEquipment,
	LightEquipment
};

Ammunition CharArrayToEnumAmmu(const char* ammu)
{
	//if (ammu[0] >= 97 && ammu[0] <= 122)
	//{
	//	ammu[0] -= 'a' - 'A';
	//}

	if (StrCmp(ammu, "HeavyEquipment"))
	{
		return Ammunition::HeavyEquipment;
	}
	else if (StrCmp(ammu, "MiddleEquipment"))
	{
		return Ammunition::MiddleEquipment;
	}
	else if (StrCmp(ammu, "LightEquipment"))
	{
		return Ammunition::LightEquipment;
	}
}

template<typename P>
class BattleShip
{
private:
	double speed;
	int countCannons;
	bool couldMakeHyperJump;
	double size;
	double fuelAmount;
	Ammunition ammunition;
	double hullStrength;
	P pilot;

public:

	BattleShip()
	{
		this->speed = 0.0;
		this->countCannons = 0;
		this->couldMakeHyperJump = false;
		this->size = 0.0;
		this->fuelAmount = 0.0;
		this->ammunition = Ammunition::LightEquipment;
		this->hullStrength = 0.0;
	}

	BattleShip(const BattleShip& otherBattleShip)
	{
		this->speed = otherBattleShip.speed;
		this->countCannons = otherBattleShip.countCannons;
		this->couldMakeHyperJump = otherBattleShip.couldMakeHyperJump;
		this->size = otherBattleShip.size;
		this->fuelAmount = otherBattleShip.fuelAmount;
		this->ammunition = otherBattleShip.ammunition;
		this->hullStrength = otherBattleShip.hullStrength;
		this->pilot = otherBattleShip.pilot;
	}

	BattleShip& operator=(const BattleShip& otherBattleShip)
	{
		if (this != &otherBattleShip)
		{
			this->speed = otherBattleShip.speed;
			this->countCannons = otherBattleShip.countCannons;
			this->couldMakeHyperJump = otherBattleShip.couldMakeHyperJump;
			this->size = otherBattleShip.size;
			this->fuelAmount = otherBattleShip.fuelAmount;
			this->ammunition = otherBattleShip.ammunition;
			this->hullStrength = otherBattleShip.hullStrength;
			this->pilot = otherBattleShip.pilot;
		}

		return *this;
	}

	BattleShip(const double& _speed, const int& _countCannons, const bool& _couldMakeHyperJump, const double& _size, const P& _pilot, const double& _fuelAmount, const Ammunition _ammunition, const double& _hullStrength)
	{
		this->speed = _speed;
		this->countCannons = _countCannons;
		this->couldMakeHyperJump = _couldMakeHyperJump;
		this->size = _size;
		this->pilot = _pilot;
		this->fuelAmount = _fuelAmount;
		this->ammunition = _ammunition;
		this->hullStrength = _hullStrength;
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
			<< " and pilot " << this->pilot
			<< " with fuel capacity: " << this->fuelAmount
			<< " ammunition: " << this->ammunition
			<< " and hull strength: " << this->hullStrength << std::endl;
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
		if (!StrCmp(typeid(_pilot).name(), "class Jedi") && !StrCmp(typeid(_pilot).name(), "class Stormtrooper"))
		{
			std::cerr << "Invalid type!" << std::endl;

			std::cin >> _pilot;
			SetPilot(_pilot);
		}

		this->pilot = _pilot;
	}

	void SetFuelCapacity(const double& _fuelAmount)
	{
		this->fuelAmount = _fuelAmount;
	}

	void SetAmmunitioin(const Ammunition _ammunition)
	{
		this->ammunition = _ammunition;
	}

	void SetHullStrength(const double& _hullStrength)
	{
		this->hullStrength = _hullStrength;
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

	double GetFuelCapacity() const
	{
		return this->fuelAmount;
	}

	Ammunition GetAmmunition() const
	{
		return this->ammunition;
	}

	double GetHullStrength() const
	{
		return this->hullStrength;
	}

	void Refueling(const double& fuel)
	{
		this->fuelAmount += fuel;
	}

	void ChangeAmmunation(char* ammu)
	{
		Ammunition newAmmunition = CharArrayToEnumAmmu(ammu);

		if (this->ammunition == newAmmunition)
		{
			return;
		}
		else if (this->ammunition == Ammunition::LightEquipment)
		{
			if (newAmmunition == Ammunition::MiddleEquipment)
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed -= this->speed * 0.30;
			}
			else
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed -= this->speed * 0.60;
			}
		}
		else if (this->ammunition == Ammunition::MiddleEquipment)
		{
			if (newAmmunition == Ammunition::LightEquipment)
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed += this->speed * 0.30;
			}
			else
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed -= this->speed * 0.30;
			}
		}
		else
		{
			if (newAmmunition == Ammunition::MiddleEquipment)
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed += this->speed * 0.30;
			}
			else if (newAmmunition == Ammunition::LightEquipment)
			{
				this->SetAmmunitioin(newAmmunition);
				this->speed += this->speed * 0.60;
			}
		}
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
			<< " and pilot " << std::endl << battleShip.GetPilot()
			<< " with fuel capacity: " << battleShip.GetFuelCapacity()
			<< " ammunition: ";

		if (battleShip.GetAmmunition() == Ammunition::HeavyEquipment)
		{
			std::cout << "HeavyEquipment ";
		}
		else if (battleShip.GetAmmunition() == Ammunition::MiddleEquipment)
		{
			std::cout << "MiddleEquipment";
		}
		else
		{
			std::cout << "LightEquipment";
		}

		std::cout << " and hull strength: " << battleShip.GetHullStrength() << std::endl;

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

		if (StrCmp(couldMakeHyperJump, "true"))
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

		std::cout << "Enter fuel amount: ";
		double fuelAmount;
		in >> fuelAmount;
		battleShip.SetFuelCapacity(fuelAmount);

		std::cout << "Enter ammunition type: ";
		char ammu[32];
		in >> ammu;
		battleShip.SetAmmunitioin(CharArrayToEnumAmmu(ammu));

		std::cout << "Enter hull strength: ";
		double hullStrength;
		in >> hullStrength;
		battleShip.SetFuelCapacity(hullStrength);

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
			position += CountSymbols(buffer) + 2;

			if (i == 1)
			{
				double num = atof(buffer);
				this->SetSpeed(num);
			}
			else if (i == 2)
			{
				this->SetCountCannons(ParseCharToInt(buffer));
			}
			else if (i == 3)
			{
				if (StrCmp(buffer, "true"))
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
			else if (i == 5)
			{
				double fuelAmount = atof(buffer);
				this->SetFuelCapacity(fuelAmount);
			}
			else if (i == 6)
			{
				this->SetAmmunitioin(CharArrayToEnumAmmu(buffer));
			}
			else
			{
				double hullStrength = atof(buffer);
				this->SetFuelCapacity(hullStrength);
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
		myFile << this->GetFuelCapacity() << std::endl;
		myFile << this->GetAmmunition() << std::endl;
		myFile << this->GetHullStrength() << std::endl;
		myFile << std::endl;

		myFile.close();
	}*/
};

template<typename T>
myVector<BattleShip<T>> RemoveWeakerBattleShips(myVector<BattleShip<T>>& battleships)
{
	myVector<BattleShip<T>> newVector;
	int size = battleships.length();

	for (int i = 0; i < size; i++)
	{
		if (battleships[i].GetHullStrength() > 50)
		{
			newVector.add(battleships[i]);
		}
	}

	return newVector;
}

//Just for testing
template<typename P>
BattleShip<P> Recharge(BattleShip<P>& battleship, const double& fuel)
{
	battleship.Refueling(fuel);

	return battleship;
}

template<typename P>
BattleShip<P> ChangeAmmunation(BattleShip<P>& battleship, const char* ammu)
{
	Ammunition newAmmunition = CharArrayToEnumAmmu(ammu);

	if (battleship.GetAmmunition() == newAmmunition)
	{
		return battleship;
	}
	else if (battleship.GetAmmunition() == Ammunition::LightEquipment)
	{
		if (newAmmunition == Ammunition::MiddleEquipment)
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() - battleship.GetSpeed() * 0.30);
		}
		else
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() - battleship.GetSpeed() * 0.60);
		}
	}
	else if (battleship.GetAmmunition() == Ammunition::MiddleEquipment)
	{
		if (newAmmunition == Ammunition::LightEquipment)
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() + battleship.GetSpeed() * 0.30);
		}
		else
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() - battleship.GetSpeed() * 0.30);
		}
	}
	else
	{
		if (newAmmunition == Ammunition::MiddleEquipment)
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() + battleship.GetSpeed() * 0.30);
		}
		else if (newAmmunition == Ammunition::LightEquipment)
		{
			battleship.SetAmmunitioin(newAmmunition);
			battleship.SetSpeed(battleship.GetSpeed() + battleship.GetSpeed() * 0.60);
		}
	}

	return battleship;
}