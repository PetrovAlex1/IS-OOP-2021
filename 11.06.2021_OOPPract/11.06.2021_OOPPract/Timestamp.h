#pragma once
#include <iostream>

class Timestamp
{
protected:
	unsigned long kleymo;
public:

	Timestamp();

	Timestamp(const unsigned long& kleymo);

	void setValue(const unsigned long& kleymo);

	unsigned long getValue() const;

	friend std::ostream& operator<<(std::ostream& out, const Timestamp& obj);

	friend std::istream& operator>>(std::istream& in, Timestamp& obj);

	Timestamp& operator+=(const int& otherKleymo);

	Timestamp operator+(const int& otherKleymo);
};