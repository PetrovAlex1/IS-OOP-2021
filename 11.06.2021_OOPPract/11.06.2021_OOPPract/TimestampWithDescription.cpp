#include "TimestampWithDescription.h"
#pragma warning(disable:4996)

TimestampWithDescription::TimestampWithDescription() : Timestamp()
{
	this->description = nullptr;
}

TimestampWithDescription::TimestampWithDescription(const unsigned long& kleymo, const char* description)
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
	this->kleymo = kleymo;
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& obj)
{
	if (this != &obj)
	{
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
		this->kleymo = kleymo;
	}

	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	delete[] this->description;
}

void TimestampWithDescription::setDescription(const char* description)
{
	if (this->description != nullptr)
	{
		delete[] this->description;
	}

	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

char* TimestampWithDescription::getDescription() const
{
	return this->description;
}

std::ostream& operator<<(std::ostream& out, const TimestampWithDescription& obj)
{
	out << "TimestampWithDescriptions description: " << obj.getDescription() << " value: " << obj.getValue() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, TimestampWithDescription& obj)
{
	std::cin.ignore();
	std::cout << "TimestampWithDescription enter description: ";
	char buffer[256];
	in.getline(buffer, 256);

	obj.setDescription(buffer);

	std::cout << "Enter value for kleymo:";
	unsigned long kleymo;
	in >> kleymo;

	obj.setValue(kleymo);

	return in;
}
