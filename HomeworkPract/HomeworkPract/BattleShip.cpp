#include "BattleShip.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)


//
//void BattleShip::SetSpeed(double _speed)
//{
//	this->speed = _speed;
//}
//
//void SetCountCannons(int _countCannons)
//{
//	this->countCannons = _countCannons;
//}
//
//void SetCouldMakeHyperJump(bool _couldMakeHyperJump)
//{
//	this->couldMakeHyperJump = _couldMakeHyperJump;
//}
//
//void SetSize(double _size)
//{
//	this->size = _size;
//}
//
//void SetPilot(P _pilot)
//{
//	while (_pilot != typeid(Jedi) && _pilot != typeid(Stormtrooper))
//	{
//		std::cerr << "Invaid type exception! The class " << _pilot << " is not allowed. Please try again!" << std::endl;
//	}
//
//	this->pilot = _pilot;
//}
//
//double GetSpeed() const
//{
//	return this->speed;
//}
//
//int GetCountCannons() const
//{
//	return this->countCannons;
//}
//
//bool GetCouldMakeHyperJump() const
//{
//	return this->couldMakeHyperJump;
//}
//
//double GetSize() const
//{
//	return this->size;
//}
//
//P BattleShip::GetPilot() const
//{
//	return this->pilot;
//}