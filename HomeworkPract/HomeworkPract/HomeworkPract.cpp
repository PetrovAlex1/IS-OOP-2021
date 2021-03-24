#include <iostream>
#include "Jedi.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "BattleShip.h"

int main()
{
	Planet Mars{"Mars", "Milky way", "Macedonia", PlanetType::IronPlanet};
	Mars.WriteOnFilePlanet("Mars.txt");
	Planet Pluto{ "Pluto", "Milky way", "Serbia", PlanetType::GasGiant };
	Pluto.WriteOnFilePlanet("Mars.txt");

	return 0;
}