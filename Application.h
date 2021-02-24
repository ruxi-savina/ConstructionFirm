#pragma once

#include "BagIterator.h"

class Application
{
private:
	Bag bag;
	void printMenu();
	void Add();
	void Delete();
	int NrOfProducts();
	int Quantity();
	void ShowProducts();
	void Filter();
	int FirstDigit(int product);
	void AddProductsForStart();

public:
	Application(const Bag& bag) { this->bag = bag; }
	void run();
};