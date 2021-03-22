#pragma once
#include <iostream>

enum class PlanetType
{
	ChthonianPlanet,
	CarbonPlanet,
	CorelessPlanet,
	DesertPlanet,
	GasDwarf,
	GasGiant,
	HeliumPlanet,
	IceGiant,
	IcePlanet,
	IronPlanet,
	LavaPlanet,
	OceanPlanet,
	ProtoPlanet,
	PuffyPlanet,
	SilicatePlanet,
	TerrestricalPlanet
};

class Planet
{
private:
	char* name;
	char* planetSystem;
	char* republic;
	PlanetType planetType;
public:

	Planet();

	Planet(const Planet& otherPlanet);

	Planet& operator=(const Planet& otherPlanet);

	Planet(const char* otherName, const char* otherPlanetSystem, const char* otherRepublic, const PlanetType _planetType);

	~Planet();

	void Print();

	void SetName(const char* _name);

	void SetPlanetSystem(const char* _planetSystem);

	void SetRepublic(const char* _republic);

	void SetPlanetType(PlanetType _planetType);

	char* GetName() const;

	char* GetPlanetSystem() const;

	char* GetRepublic() const;

	PlanetType GetPlanetType() const;

	friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
};

template<class T>

void PrintInfo(const T object);