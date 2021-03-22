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
	else if (rank == "Padawan")
	{
		return JediRank::Padawan;
	}
	if (rank == "CarbonPlanet")
	{
		return PlanetType::CarbonPlanet;
	}
	else if (rank == "ChthonianPlanet")
	{
		return PlanetType::ChthonianPlanet;
	}
	else if (rank == "CorelessPlanet")
	{
		return PlanetType::CorelessPlanet;
	}
	else if (rank == "DesertPlanet")
	{
		return PlanetType::DesertPlanet;
	}
	else if (rank == "GasDwarf")
	{
		return PlanetType::GasDwarf;
	}
	else if (rank == "GasGiant")
	{
		return PlanetType::GasGiant;
	}
	else if (rank == "HeliumPlanet")
	{
		return PlanetType::HeliumPlanet;
	}
	else if (rank == "IceGiant")
	{
		return PlanetType::IceGiant;
	}
	else if (rank == "IcePlanet")
	{
		return PlanetType::IcePlanet;
	}
	else if (rank == "IronPlanet")
	{
		return PlanetType::IronPlanet;
	}
	else if (rank == "LavaPlanet")
	{
		return PlanetType::LavaPlanet;
	}
	else if (rank == "OceanPlanet")
	{
		return PlanetType::OceanPlanet;
	}
	else if (rank == "ProtoPlanet")
	{
		return PlanetType::ProtoPlanet;
	}
	else if (rank == "PuffyPlanet")
	{
		return PlanetType::PuffyPlanet;
	}
	else if (rank == "SilicatePlanet")
	{
		return PlanetType::SilicatePlanet;
	}
	else if (rank == "TerrestricalPlanet")
	{
		return PlanetType::TerrestricalPlanet;
	}
	else if (rank == "SquadLeader")
	{
		return TrooperRank::SquadLeader;
	}
	else if (rank == "RegimentCommander")
	{
		return TrooperRank::RegimentCommander;
	}
	else if (rank == "Commander")
	{
		return TrooperRank::Commander;
	}
	else if (rank == "Enlisted")
	{
		return TrooperRank::Enlisted;
	}
	else if (rank == "Sergeant")
	{
		return TrooperRank::Sergeant;
	}
	else if (rank == "PlatoonLeader")
	{
		return TrooperRank::PlatoonLeader;
	}
	else if (rank == "GeneralOfLegion")
	{
		return TrooperRank::GeneralOfLegion;
	}
	else if (rank == "CompanyLeader")
	{
		return TrooperRank::CompanyLeader;
	}
	else if (rank == "BattalionCommander")
	{
		return TrooperRank::BattalionCommander;
	}
	else if (rank == "Trooper")
	{
		return TrooperRank::Trooper;
	}
}

Stormtrooper CreateTrooper()
{
	Stormtrooper trooper;
	char id[8];
	std::cin >> id;
	trooper.SetID(id);

	char rank[32];
	std::cin >> rank;
	trooper.SetRank(CharArrayToEnum<TrooperRank>(rank));

	char type[32];
	std::cin >> type;
	trooper.SetType(type);

	Planet planet;
	planet = CreatePlanet();
	trooper.SetPlanet(planet);
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
	planet = CreatePlanet();
	jedi.SetPlanet(planet);

	char spicies[32];
	std::cin >> spicies;
	jedi.SetSpicies(spicies);

	char militaryRank[32];
	std::cin >> militaryRank;
	jedi.SetMilitaryRank(militaryRank);

	return jedi;
}
