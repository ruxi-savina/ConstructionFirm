#include "BagIterator.h"
#include <exception>

#include <iostream>

//n is the capacity of the bag

// O(n)
BagIterator::BagIterator(const Bag& bag) : bag{bag}
{
	this->first();
}

// Theta(1)
bool BagIterator::valid() const
{
	return currentIndex < bag.capacity;
}

// O(n)
void BagIterator::first()
{
	currentIndex = 0;
	while (currentIndex < bag.capacity && bag.elements[currentIndex] == NULL_INT)
		currentIndex++;
	nrOfAppearances = 1;
}

// O(n)
void BagIterator::next()
{
	if (!valid())
		throw std::exception("!INVALID ITERATOR!");

	if (nrOfAppearances < bag.frequencies[currentIndex])
		nrOfAppearances++;

	else 
	{
		currentIndex++;
		while (currentIndex < bag.capacity && bag.elements[currentIndex] == NULL_INT)
			currentIndex++;
		nrOfAppearances = 1;
	}
}

// Theta(1)
int BagIterator::getCurrent() const
{
	if (!valid())
		throw std::exception("!INVALID ITERATOR!");
	return bag.elements[currentIndex];
}
