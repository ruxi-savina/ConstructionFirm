#pragma once
#include "BagIterator.h"
#include <algorithm>

#define MAX_CAP 100
#define NULL_INT -1

class BagIterator;

class Bag
{
	friend class BagIterator;

private:
	int elements[MAX_CAP];
	int frequencies[MAX_CAP];
	int next[MAX_CAP];
	int firstEmpty;
	int capacity;
	int nrElems;
	int HFunction(int key) const { return key % this->capacity; }
	//auxiliary funtions
	void updateFirstEmpty();

public:
	//Constructor - creates an empty bag
	Bag();
	~Bag() = default;

	/*
	@brief Adds an element to the bag
	IN: the elemnt we want to add
	OUT: -
	*/
	void add(int e);

	/*
	@brief Deletes an element from the bag
	IN: the elemnt we want to delete
	OUT: true if the operation is possible(the element exists in the bag), and false otherwise
	*/
	bool remove(int e);

	/*
	@brief Searches for an element in the bag
	IN: the element we are looking for
	OUT: true if the element exists in the bag, and false otherwise
	*/
	bool search(int e) const;

	/*
	@brief Calculates the number of elements from the bag
	IN: -
	OUT: the number of elements from the bag
	*/
	int size() const;

	/*
	@brief Calculates the number of occurences of an element in the bag
	IN: an element
	OUT: the frequence of the element
	*/
	int nrOccurrences(int i) const;

	/*
	@brief creates and iterator for the bag
	IN: -
	OUT: the iterator for the bag
	*/
	BagIterator iterator() const;
};