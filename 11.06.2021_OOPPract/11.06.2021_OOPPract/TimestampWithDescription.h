#pragma once
#include <iostream>
#include "Timestamp.h"

class TimestampWithDescription : public Timestamp
{
private:
	char* description;
public:

	TimestampWithDescription();

	TimestampWithDescription(const unsigned long& kleymo, const char* description);

	TimestampWithDescription& operator=(const TimestampWithDescription& obj);

	~TimestampWithDescription();

	void setDescription(const char* description);

	char* getDescription() const;

	friend std::ostream& operator<<(std::ostream& out, const TimestampWithDescription& obj);

	friend std::istream& operator>>(std::istream& in, TimestampWithDescription& obj);
};