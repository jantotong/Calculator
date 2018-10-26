#ifndef QUEUE_H
#define QUEUE_H
#include "Linkedlist.h"

using namespace std;
template <class T>
class Queue : protected Linkedlist <T>
{
protected:
	//inheritting from Linkedlist 

public:
	//Constructors
	Queue()
	{
		Linkedlist<T>::Linkedlist(); //create and empty linklist using constructor of base class
	}
	//Copy Constructor
	Queue(const Queue<T>& aQueue)
	{
		Linkedlist::Linkedlist(aQueue);
	}

	void enqueue(const T& newElement)
	{
		return Linkedlist<T>::AddLast(newElement);
	}

	T dequeue()
	{
		Linkedlist<T>::removeFirst();
		return Linkedlist<T>::dq();
	}

	void queueTop()
	{
		cout << Linkedlist<T>::getEntry(1) << endl;
	}

	T front()
	{
		return Linkedlist<T>::getEntry(1);
	}

	T rear()
	{
		return Linkedlist<T>::getLastEntry();
	}

	void empty()
	{
		return  Linkedlist<T>::Empty();
	}

	int getSize()
	{
		return Linkedlist<T>::getLength();
	}

	void printQueue()
	{
		for (int i = 1; i < getSize() + 1; i++)
		{
			cout << Linkedlist<T>::getEntry(i) << endl;
		}
	}
};
#endif
