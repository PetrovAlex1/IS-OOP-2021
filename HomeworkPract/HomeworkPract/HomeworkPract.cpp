#include <iostream>
#include "Jedi.h"
#include "Planet.h"
#include "Stormtrooper.h"

int main()
{
	Planet Mars{ "Mars", "Mily way", "Republica", PlanetType::PuffyPlanet };
	PrintInfo(Mars);
}