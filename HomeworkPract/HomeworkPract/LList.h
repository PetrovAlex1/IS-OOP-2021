#pragma once
#include <iostream>

template<typename T>
struct LList
{
private:
	T data;
	LList* next;
public:

	LList(const T& data);

	~LList();

	void PushFront(const T& data);

	void PushBack(const T& data);

	void PopFront();

	//void Reverse();

	void PrintLog();
};

template<typename T>
LList<T>::LList(const T& data)
{
	this->data = data;
	this->next = nullptr;
}

template<typename T>
LList<T>::~LList()
{
	//LList<T>* current = this;

	while (this->next != nullptr)
	{
		this->PopFront();
		/*LList<T>* temp = current;
		current = current->next;
		temp->next = nullptr;
		delete temp;*/
	}
}

template<typename T>
void LList<T>::PushFront(const T& data)
{
	LList<T>* added = new LList<T>(data);
	added->next = this;
	this = added;
}

template<typename T>
void LList<T>::PushBack(const T& data)
{
	LList<T>* added = new LList<T>(data);
	LList<T>* current = this;

	while (current->next)
	{
		current = current->next;
	}

	current->next = added;
}

template<typename T>
void LList<T>::PopFront()
{
	LList<T>* temp = this;

	if (this->next)
	{
		*this = *this->next;
	}

	delete temp;
}

//template<typename T>
//void LList<T>::Reverse()
//{
//	LList<T>* reversed = new LList<T>(*this);
//	LList<T>* current = this;
//
//	while (current->next)
//	{
//		reversed->PushFront(current->next->data);
//		current = current->next;
//	}
//
//	this->~LList();
//	this = reversed;
//}

template<typename T>
void LList<T>::PrintLog()
{
	LList<T>* current = this;

	while (current)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}



