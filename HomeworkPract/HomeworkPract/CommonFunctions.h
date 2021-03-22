#pragma once
#include <iostream>
#include "Jedi.h"
#include "Planet.h"
#include "Stormtrooper.h"

template<typename E>

E CharArrayToEnum(char* rank)
{
	if (rank == "Knight")
	{
		return JediRank::Knight;
	}
	else if (rank == "Master")
	{
		return JediRank::Master;
	}
	else if (rank == "GrandMaster")
	{
		return JediRank::GrandMaster;
	}
	else if(rank == "Padawan")
	{
		return JediRank::Padawan;
	}
	if (rank == PlanetType::CarbonPlanet)
	{
		return PlanetType::CarbonPlanet;
	}
	else if (rank == PlanetType::ChthonianPlanet)
	{
		return PlanetType::ChthonianPlanet;
	}
	else if (rank == PlanetType::CorelessPlanet)
	{
		return PlanetType::CorelessPlanet;
	}
	else if (rank == PlanetType::DesertPlanet)
	{
		return PlanetType::DesertPlanet;
	}
	else if (rank == PlanetType::GasDwarf)
	{
		return PlanetType::GasDwarf;
	}
	else if (rank == PlanetType::GasGiant)
	{
		return PlanetType::GasGiant;
	}
	else if (rank == PlanetType::HeliumPlanet)
	{
		
	}
	else if (rank == PlanetType::IceGiant)
	{
		
	}
	else if (rank == PlanetType::IcePlanet)
	{
		
	}
	else if (rank == PlanetType::IronPlanet)
	{
	
	}
	else if (rank == PlanetType::LavaPlanet)
	{
		
	}
	else if (rank == PlanetType::OceanPlanet)
	{
		
	}
	else if (rank == PlanetType::ProtoPlanet)
	{
		
	}
	else if (rank == PlanetType::PuffyPlanet)
	{
		
	}
	else if (rank == PlanetType::SilicatePlanet)
	{
		
	}
	else
	{
		strcpy(planetType, "TerrestricalPlanet");
		return planetType;
	}
}

Planet CreatePlanet()
{
	Planet planet;
	char name[32];
	std::cin >> name;
	planet.SetName(name);

	char planetSystem[32];
	std::cin >> planetSystem;
	planet.SetPlanetSystem(planetSystem);

	char republic[32];
	std::cin >> republic;
	planet.SetRepublic(republic);

	char planetType[32];
	std::cin >> planetType;
	planet.SetPlanetType(CharArrayToEnum<PlanetType>(planetType));
}

Jedi CreateJedi()
{
	Jedi jedi;
	char name[32];
	std::cin >> name;
	jedi.SetName(name);

	char rank[32];
	std::cin >> rank;
	jedi.SetRank(CharArrayToEnum<JediRank>(rank));

	float midichlorian;
	std::cin >> midichlorian;
	jedi.SetMidichlorian(midichlorian);

	Planet planet;
	char planetName[16];
	std::cin >> planetName;
	planet.SetName(planetName);
	jedi.SetPlanet(planet);

	char spicies[32];
	std::cin >> spicies;
	jedi.SetSpicies(spicies);

	char militaryRank[32];
	std::cin >> militaryRank;
	jedi.SetMilitaryRank(militaryRank);

	return jedi;
}
