#include <assert.h>
#include "Bag.h"
#include "BagTest.h"
#include "BagIterator.h"
#include <iostream>


void Test::testBag()
{
	Bag bag{};
	assert(bag.size() == 0);
//add with collision
	bag.add(1234);
	bag.add(2234);
	bag.add(3234);
	bag.add(4234);
	bag.add(5234);
	bag.add(6234);
	bag.add(7234);
	bag.add(8234);
	bag.add(9234);
	bag.add(9234);
	bag.add(9234);
//size
	assert(bag.size() == 11);
//search every element
	for (int i = 1; i <= 9; i++)
	{
		int number = i * 1000 + 234;
		assert(bag.search(number) == true);
	}
//nrOccurrences
	assert(bag.nrOccurrences(9234) == 3);
	assert(bag.nrOccurrences(1234) == 1);
	assert(bag.nrOccurrences(7324) == 0);
//remove
	bag.remove(9234);
	bag.remove(9234);
	bag.remove(1234);
//search every element
	assert(bag.size() == 8);
	for (int i = 2; i <= 9; i++)
	{
		int product = i * 1000 + 234;
		assert(bag.search(product) == true);
	}
	assert(bag.search(1234) == false);
	assert(bag.remove(1234) == false);
//add with another key
	bag.add(7324);
	bag.add(8932);
	bag.add(1400);
	assert(bag.size() == 11);
	assert(bag.search(7324) == true);
	assert(bag.search(8932) == true);
	assert(bag.search(1400) == true);
//remove all
	bag.remove(2234);
	bag.remove(3234);
	bag.remove(4234);
	bag.remove(5234);
	bag.remove(6234);
	bag.remove(7234);
	bag.remove(8234);
	bag.remove(9234);
	bag.remove(7324);
	bag.remove(8932);
	bag.remove(1400);
//size empty
	assert(bag.size() == 0);
}

void Test::testBagIterator()
{
	Bag bag{};
	bag.add(3647);
	BagIterator iteratorBuid = bag.iterator();

	bag.add(4836);
	bag.add(3636);
	bag.add(4836);
	bag.add(4836);
	bag.add(2736);
	bag.add(3849);
	bag.add(2635);
	bag.add(6543);
	bag.add(9634);
	bag.add(9634);

	BagIterator iterator = bag.iterator();

//valid and next
	while (iterator.valid())
	{
		int product = iterator.getCurrent();
		assert(bag.search(product) == true);
		iterator.next();
	}

//exception for getCurrent
	try
	{
		iterator.getCurrent();
	}catch (std::exception & exc) { assert(strcmp(exc.what(), "!INVALID ITERATOR!") == 0); }

//exception for next
	try
	{
		iterator.next();
	}catch (std::exception & exc) { assert(strcmp(exc.what(), "!INVALID ITERATOR!") == 0); }

//first
	iterator.first();
	assert(iterator.valid() == true);
}

void Test::testAll()
{
	testBag();
	testBagIterator();
}
