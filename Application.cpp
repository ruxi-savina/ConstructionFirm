#include <iostream>
#include "Application.h"
#include <vector>
#include <iostream>

using namespace std;

// Theta(1)
void Application::printMenu()
{
	cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
	cout << " MENU\n";
	cout << "1. Add a product\n";
	cout << "2. Delete a product\n";
	cout << "3. See the number of products in the storage\n";
	cout << "4. See the quantity of a product\n";
	cout << "5. Filter by type\n";
	cout << "6. Show products\n";
	cout << "0. Exit\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n\n";

}

// O(n)
void Application::Add()
{
	int product;
	cout << "Enter the code of the product: ";
	cin >> product;
	bag.add(product);
}

// O(n)
void Application::Delete()
{
	int product;
	cout << "Enter the code of the product: ";
	cin >> product;
	if (!bag.remove(product))
		throw exception("There are no products in the storage with this code\n");
}

// O(n)
int Application::NrOfProducts()
{
	int nrOfProducts = 0;
	BagIterator iterator = bag.iterator();
	while (iterator.valid())
	{
		nrOfProducts ++;
		iterator.next();
	}
	return nrOfProducts;
}

// O(n)
int Application::Quantity()
{
	int product, quantity = 0;
	bool ok = 0;
	BagIterator iterator = bag.iterator();
	cout << "Enter the code of the product: ";
	cin >> product;
	if (bag.search(product) == 0)
		throw std::exception("There are no products in the storage with this code\n");
	while (iterator.valid() && ok == 0)
	{
		if(iterator.getCurrent() == product)
			ok = 1;
		iterator.next();
	}
	while (iterator.valid() && iterator.getCurrent() == product)
	{
		quantity++;
		iterator.next();
	}
	quantity++;
	return quantity;
	
}

// O(n)
void Application::ShowProducts()
{
	BagIterator iterator = bag.iterator();
	cout << "List of products:\n";
	while (iterator.valid())
	{
		cout << iterator.getCurrent() << " ";
		iterator.next();
	}
}

// Theta(1)
int Application::FirstDigit(int product)
{
	while (product > 10)
		product /= 10;
	return product;
}

// O(n)
void Application::Filter()
{
	vector<int> filteredProducts;
	vector<string> types{"", "DIY", "thermic", "electric", "sanitary", "otherProducts"};
	string product;
	int type;
	BagIterator iterator = bag.iterator();
	cout << "Enter the type of products you want to filter after <DIY, thermic, electric, sanitary, otherProducts>: ";
	cin >> product;
	cin.get();

//exception
	vector<string>::iterator iter = find(types.begin() + 1, types.end(), product);
	if (iter == types.end())
		throw std::exception("!Invalid type!");

//for other products
	if (product == "otherProducts")
	{
		while (iterator.valid())
		{
			int firstDigit = FirstDigit(iterator.getCurrent());
			if (firstDigit > 4 && firstDigit < 10)
				filteredProducts.push_back(iterator.getCurrent());
			iterator.next();
		}
	}
	else
	{
//for the rest
		for (int i = 1; i <= 4; i++)
			if (types[i] == product)
				type = i;

		while (iterator.valid())
		{
			if (FirstDigit(iterator.getCurrent()) == type)
				filteredProducts.push_back(iterator.getCurrent());
			iterator.next();
		}
	}

	if (filteredProducts.size() == 0)
		throw std::exception("There are no products of this type");
	else
	{
		cout << "\nFiltered products:\n";
		for (auto product : filteredProducts)
			cout << product << " ";
	}
}

// O(n);
void Application::AddProductsForStart()
{
	bag.add(1234);
	bag.add(4257);
	bag.add(6354);
	bag.add(2341);
	bag.add(5434);
	bag.add(3251);
	bag.add(9234);
	bag.add(1453);
	bag.add(2353);
	bag.add(1756);
	bag.add(1745);
	bag.add(3562);
	bag.add(4257);
	bag.add(1234);
	bag.add(4326);
}


// O(p * n), where p is the number of options chosen by the user
void Application::run()
{
	int opt = 1;
	bool stop = false;
	AddProductsForStart();
	while (stop == false)
	{
		try
		{
			printMenu();
			cout << "\n>>> ";
			cin >> opt;
			switch (opt)
			{
			case(1):
				Add();
				break;

			case(2):
				Delete();
				break;

			case(3):
				if (NrOfProducts() == 1)
					cout << "There is 1 product in the storage\n";
				else
					cout << "There are " << NrOfProducts() << " products in the storage\n";
				break;

			case(4):
				cout << "The quantity of the product: " << Quantity();
				break;

			case(5):
				Filter();
				break;

			case(6):
				ShowProducts();
				break;

			case(0):
				stop = true;
				break;

			default:
				cout << "\n!Invalid command!\n";
				break;
			}
		}
		catch (std::exception & exception) { cout << exception.what(); }
	}
}
