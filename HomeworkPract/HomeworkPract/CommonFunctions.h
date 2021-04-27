#pragma once
#include <iostream>
#include <functional>
#include "myVector.h"

template<typename T>
inline void map(myVector<T>& vect, std::function<T(T)> f)
{
	int length = vect.length();

	for (int i = 0; i < length; i++)
	{
		vect[i] = f(vect[i]);
	}
}

template<typename T>
inline myVector<T> filter(myVector<T>& vect, std::function<bool(T)> predicate)
{
	myVector<T> result;
	int length = vect.length();

	for (int i = 0; i < length; i++)
	{
		if (predicate(vect[i]))
		{
			result.add(vect[i]);
		}
	}

	return result;
}

inline int ParseCharToInt(char* text)
{
	int number = 0;
	int d = 10;

	for (int i = 0; text[i] != '\0'; i++)
	{
		number = number * d + text[i] - 48;
	}

	return number;
}

inline int CountSymbols(char* text)
{
	int counter = 0;
	int i = 0;

	while (text[i] != '\0')
	{
		counter++;
		i++;
	}

	return counter;
}

inline bool StrCmp(char* text1, const char* text2)
{
	int i = 0;

	while (text1[i] != '\0')
	{
		if (text1[i] != text2[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

inline bool StrCmp(const char* text1, const char* text2)
{
	int i = 0;

	while (text1[i] != '\0')
	{
		if (text1[i] != text2[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

