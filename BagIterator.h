#pragma once
#include "Bag.h"

class Bag;

class BagIterator
{
	friend class Bag;

private:
	const Bag& bag; 
	int currentIndex;
	int nrOfAppearances;

	//Constructor - creates an iterator for the bag
	BagIterator();
	BagIterator(const Bag& bag);

public:
	
	/*
	@brief Verifies if the current element from the iterator is a valid one
	IN: -
	OUT: true if the current element is valid, and false otherwise
	*/
	bool valid() const;

	/*
	@brief Returns a new iterator which has the current element the first element from the bag; the iterator is invalid if the bag is empty
	IN: -
	OUT: the new iterator
	*/
	void first();

	/*
	@brief Returns a new iterator which has the current element the next element from the bag; the iterator is invalid if the bag is empty
	IN: -
	OUT: the new iterator
	throws: exception if the iterator is not valid
	*/
	void next(); 

	/*
	@brief Finds the current element from the iterator
	IN: -
	OUT: the current element from the iterator
	throws: exception if the iterator is not valid
	*/
	int getCurrent() const;
};