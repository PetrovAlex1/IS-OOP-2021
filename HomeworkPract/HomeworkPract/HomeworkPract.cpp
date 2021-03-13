#include <iostream>
#include "Jedi.hpp"
#include "Planet.hpp"
#include "Stormtrooper.hpp"

int main()
{
	Planet Mars;
	Mars.SetName("Mars");
	Mars.SetPlanetSystem("Milky way");
	Mars.SetRepublic("Marcy");
	Mars.Print();
}