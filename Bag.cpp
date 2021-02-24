#include "Bag.h"

//n is the capacity of the bag

// O(n)
Bag::Bag()
{
	capacity = MAX_CAP;
	firstEmpty = 0;
	nrElems = 0;
	for (int i = 0; i < capacity; i++)
	{
		this->elements[i] = NULL_INT;
		this->frequencies[i] = 0;
		this->next[i] = NULL_INT;
	}
}

// O(n)
void Bag::updateFirstEmpty()
{
    while (firstEmpty < capacity && elements[firstEmpty] != NULL_INT)
        firstEmpty++;
}

// O(n)
void Bag::add(int e)
{
    int position = this->HFunction(e);

    if (elements[position] == NULL_INT)
    {
        elements[position] = e;
        frequencies[position] = 1;
        if (firstEmpty == position)
            updateFirstEmpty();
    }
    else 
    {
        int currentPosition = position;
        while (next[currentPosition] != NULL_INT)
        {
            if (elements[currentPosition] == e)
            {
                frequencies[currentPosition]++;
                nrElems++;
                return;
            }
            currentPosition = next[currentPosition];
        }
       
        if (elements[currentPosition] == e)
            frequencies[currentPosition]++;
        else
        {
            elements[firstEmpty] = e;
            frequencies[firstEmpty] = 1;
            next[currentPosition] = firstEmpty;
            updateFirstEmpty();
        }
    }
    nrElems++;
}


// O(n)
bool Bag::remove(int e)
{
    int actualNode = HFunction(e);
    int previousNode = NULL_INT;
    int index = 0;

    while (actualNode != NULL_INT && elements[actualNode] != e) 
    {
        previousNode = actualNode;
        actualNode = next[actualNode];
    }

    if (actualNode == NULL_INT) // we didn't find the element in the bag
        return false;

    if (frequencies[actualNode] != 1)
    {
        frequencies[actualNode]--;
        nrElems--;
        return true;
    }
 
   bool doneMoving = false;
    do 
    {
        int currentPosition = next[actualNode]; 
        int previousPos = actualNode;

        while (currentPosition != NULL_INT && HFunction(elements[currentPosition]) != actualNode)
        {
            previousPos = currentPosition;
            currentPosition = next[currentPosition];
        }

        if (currentPosition == NULL_INT) 
            doneMoving = true;
        
        else 
        {
            elements[actualNode] = elements[currentPosition];
            frequencies[actualNode] = frequencies[currentPosition];
            actualNode = currentPosition;
            previousNode = previousPos;
        }
    } while (doneMoving == false);

    if (previousNode != NULL_INT) 
        next[previousNode] = next[actualNode];
       
    elements[actualNode] = NULL_INT;
    next[actualNode] = NULL_INT;
    frequencies[actualNode] = 0;

    if (actualNode < firstEmpty) 
        firstEmpty = actualNode;
     
    nrElems--;
    return true;
}

// O(n)
bool Bag::search(int e) const 
{ 
    int currentPosition = HFunction(e);
    while (currentPosition != NULL_INT) 
    {
        if (elements[currentPosition] == e) 
            return true;
        currentPosition = next[currentPosition];
    }
    return false;
}

//Theta(1)
int Bag::size() const
{
    return nrElems;
}

// O(n)
int Bag::nrOccurrences(int i) const
{
    int currentPosition = HFunction(i);
    while (currentPosition != NULL_INT)
    {
        if (elements[currentPosition] == i)
            return frequencies[currentPosition];
        currentPosition = next[currentPosition];
    }
    return 0;
}

// Theta(1)
BagIterator Bag::iterator() const
{
    return BagIterator{ *this };
}
