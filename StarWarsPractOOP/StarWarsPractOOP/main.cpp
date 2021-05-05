#include <iostream>
#include "Jedi.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "BattleShip.h"
#include "myVector.h"
#include "CommonFunctions.h"
#include "LList.h"

int main()
{
	LList<int> integers;
	integers.PushBack(1);
	integers.PushBack(2);
	integers.PushBack(3);
	integers.PushBack(4);
	integers.PrintLog();
	std::cout << "Recursion Reverse" << std::endl;
	recursionReverse(integers);
	integers.PrintLog();

	Planet mars{ "Mars", "Milky way", "Macedonia", PlanetType::ChthonianPlanet };
	Planet pluto{ "Pluto", "Milky way", "Macedonia", PlanetType::IcePlanet };
	Planet glo{ "Glo", "Milky way", "Macedonia", PlanetType::CarbonPlanet };

	Jedi yoda{ "Yoda", JediRank::GrandMaster, 1212.0, mars, "spi", "Commander" };
	Jedi ivan{ "Ivan", JediRank::GrandMaster, 2342.0, pluto, "gka", "Polk" };
	Jedi drag{ "Drag", JediRank::GrandMaster, 342.0, glo, "Opa", "Serji" };
	Jedi lag{ "Lag", JediRank::GrandMaster, 7812.0, mars, "asa", "Merji" };

	BattleShip<Jedi> core1{ 120, 12, false, 545, yoda, 100, Ammunition::LightEquipment, 100 };
	BattleShip<Jedi> core2{ 130, 10, false, 40, ivan, 90, Ammunition::MiddleEquipment, 30 };
	BattleShip<Jedi> core3{ 30, 9, true, 80, drag, 60, Ammunition::HeavyEquipment, 110 };

	myVector<BattleShip<Jedi>> battleships;
	battleships.add(core1);
	battleships.add(core2);
	battleships.add(core3);

	battleships = RemoveWeakerBattleShips(battleships);

	battleships.print();

	map(battleships, { [](BattleShip<Jedi> battleship) -> BattleShip<Jedi> {return Recharge(battleship, 50); } });

	battleships.print();

	battleships = filter(battleships, { [](BattleShip<Jedi> battleship) -> bool {return battleship.GetCouldMakeHyperJump(); } });

	std::cout << std::endl << "battleships which could make hyper jump are: " << std::endl;

	battleships.print();

	map(battleships, { [](BattleShip<Jedi> battleship) -> BattleShip<Jedi> {return ChangeAmmunation(battleship, "LightEquipment"); } });

	std::cout << std::endl << "Changed ammu : " << std::endl;

	battleships.print();

	return 0;
}