#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T data, Node<T>* next) : data(data), next(next) {}
};

template<typename T>
class LList
{
private:
	Node<T>* head;
public:

	LList();

	~LList();

	void PushFront(const T& data);

	void PushBack(const T& data);

	void pushAt(const int& index, const T& data);

	void RemoveAll();

	void PopFront();

	void PopBack();

	void PopAt(const int& index);

	void Reverse();

	int Size();

	Node<T>* getIth(const int& index);

	void PrintLog();
};

template<typename T>
LList<T>::LList()
{
	head = nullptr;
}

template<typename T>
LList<T>::~LList()
{
	RemoveAll();
}

template<typename T>
void LList<T>::PushFront(const T& data)
{
	head = new Node<T>(data, head);
}

template<typename T>
void LList<T>::PushBack(const T& data)
{
	Node<T>* added = new Node<T>(data, nullptr);
	Node<T>* current = head;

	if (current == nullptr)
	{
		head = added;
		return;
	}

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = added;
}

template<typename T>
void LList<T>::pushAt(const int& index, const T& data)
{
	if (index == 0)
	{
		exit(0);
	}
	if (index == 1)
	{
		PushFront(data);
	}

	Node<T>* current = head;

	for (int i = index - 1; i > 1; --i)
	{
		current = current->next;

		if (current == nullptr)
		{
			exit(0);
		}
	}

	Node<T>* added = new Node<T>(data, nullptr);// 1 2 3 4
	Node<T>* temp = current->next;
	current->next = added;
	added->next = temp;
}

template<typename T>
void LList<T>::RemoveAll()
{
	Node<T>* curr = head;

	while (curr != nullptr)
	{
		Node<T>* temp = curr->next;
		delete curr;
		curr = temp;
	}
}

template<typename T>
void LList<T>::PopFront()
{
	if (head == nullptr)
	{
		return;
	}

	Node<T>* toBeDeleted = head;
	head = head->next;
	delete toBeDeleted;
}

template<typename T>
inline void LList<T>::PopBack()
{
	Node<T>* current = head;

	while (current->next->next != nullptr)
	{
		current = current->next;
	}

	delete current->next;
	current->next = nullptr;
}

template<typename T>
void LList<T>::PopAt(const int& index)
{
	if (index == 0)
	{
		return;
	}
	if (index == 1)
	{
		PopFront();
	}

	Node<T>* current = head;

	for (int i = index - 1; i > 1; --i)
	{
		current = current->next;

		if (current == nullptr)
		{
			return;
		}
	}

	Node<T>* temp = current->next->next;
	delete[] current->next;
	current->next = temp;
}

template<typename T>
void LList<T>::Reverse()
{
	Node<T>* newHead = new Node<T>(head->data, nullptr);
	Node<T>* currentHead = head->next;

	while (currentHead != nullptr)
	{
		newHead = new Node<T>(currentHead->data, newHead);
		currentHead = currentHead->next;
	}

	RemoveAll();
	head = newHead;
}

template<typename T>
int LList<T>::Size()
{
	int counter = 0;
	Node<T>* current = head;

	for (counter ; current != nullptr ; counter++)
	{
		current = current->next;
	}

	return counter;
}

template<typename T>
Node<T>* LList<T>::getIth(const int& index)
{
	if (index == 0)
	{
		exit(0);
	}
	if (index == 1)
	{
		return head;
	}

	Node<T>* current = head;	

	for (int i = index - 1; i > 0; --i)
	{
		current = current->next;

		if (current == nullptr)
		{
			exit(0);
		}
	}

	return current;
}

template<typename T>
void LList<T>::PrintLog()
{
	Node<T>* current = head;

	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

template<typename T>
void recursionReverse(LList<T>& list)
{
	static int size = list.Size();
	static int index = 1;
	
	if (size == 0)
	{
		return;
	}

	list.PushFront(list.getIth(index)->data);
	index++;
	list.PopAt(index);
	size--;
	recursionReverse(list);
}