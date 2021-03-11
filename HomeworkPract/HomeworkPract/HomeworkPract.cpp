#include <iostream>
#include "Jedi.hpp"
#include "Planet.hpp"
#include "Stormtrooper.hpp"

int main()
{
	Planet Mars{"Mars", "Milky way", "Republic of Macedonia"};
	Jedi Anakin{ "Anakin", JediRank::GrandMaster, 12.1f, Mars, "Spicies", "Comander" };
	Anakin.Print();
}