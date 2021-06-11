#include "Timestamp.h"

Timestamp::Timestamp()
{
	this->kleymo = 0;
}

Timestamp::Timestamp(const unsigned long& kleymo)
{
	this->kleymo = kleymo;
}

void Timestamp::setValue(const unsigned long& kleymo)
{
	this->kleymo = kleymo;
}

unsigned long Timestamp::getValue() const
{
	return this->kleymo;
}

Timestamp& Timestamp::operator+=(const int& otherKleymo)
{
	this->kleymo += otherKleymo;

	return *this;
}

Timestamp Timestamp::operator+(const int& otherKleymo)
{
	unsigned long resultKleymo = this->kleymo + otherKleymo;
	Timestamp result(resultKleymo);

	return result;
}

std::ostream& operator<<(std::ostream& out, const Timestamp& obj)
{
	out << "Timestamp value: " << obj.getValue() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Timestamp& obj)
{
	std::cout << "Timestamp enter value: ";
	unsigned long kleymo;
	in >> kleymo;
	obj.setValue(kleymo);

	return in;
}
