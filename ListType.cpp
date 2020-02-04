#include "ListType.h"
#include <iostream>
using namespace std;
#include <string>

void ListType::clear()
{
	// this changes the user's
	// ability to access the elements in the array,
	// effectively "creating a new array"
	// by setting pointer to first location
	// and overwriting all elements
	// starting at index 0
	// and allowing user to call
	// add to continue 
	// "initializing" their array
	count = 0;

}

int ListType::getCount() const
{
	
	return this->count;

}

void ListType::add(int item)
{
	// check
	// to make sure the user
	// isn't accessing memory outside
	// the bounds of our 
	// static array allocation
	if (isFull()) {

		cout << "The array cannot hold anymore elements.";

		cout << endl;

		cout << endl;

		return;

	}

	// if within bounds place item at the end of the list
	// and increment the users access to next element
	array[count] = item;
	count++;

}

void ListType::insertItem(int item, int insertionIndex)
{

	int n = count;
	n++;

	if (isFull())
	{

		cout << "The array cannot hold anymore elements.";

		cout << endl;

		cout << endl;

	}

	for (int i = n; i >= insertionIndex; i--)
	{

		array[i] = array[i - 1];

	}

	array[insertionIndex - 1] = item;
	count++;

}

void ListType::deleteItem(int item)
{

	if (isEmpty() || count == NULL)
	{

		cout << "There is nothing to delete in this array.";

		cout << endl;

		cout << endl;

	}
	
	// we iterate through array
	// until we reach our item
	for  (int i = 0; i < 10; i++)
	{

		// once we find it
		if (array[i] == item)
		{

			// we delete the item, by
			// popping the first element
			// placed into the queue
			// and placing it into the
			// index to be "deleted"
			array[i] = array[count - 1];
			
			// and then we decrement
			// the available array size
			// by 1 to further simulate deletion
			count--;

		}

	}

}

bool ListType::isEmpty() const
{
	
	return (count == 0);

}

bool ListType::isFull() const
{

	return (count == maxSize);

}

void ListType::show()
{

	if (count == 0 || NULL)
	{

		cout << "There are currently no values in your array.";

		cout << endl;

	}
	
	for (int i = 0; i < count; i++)
	{

		cout << array[i];

		cout << endl;

	}

}
// our main function
// that drives our program
// and allows user to
// simulate operations
// on an array of integers
void ListType::menu()
{

	int userInput;
	int itemToPass;
	int indexToPass;

	cout << "Please choose from the following list and enter an integer to perform an operation on a pre-allocated array:" << endl;

	cout << endl;

		do {

			cout << "Enter 1: to Add an element to the end of the array." << endl;
			cout << "Enter 2: to Insert an integer of your choice at your specified location." << endl;
			cout << "Enter 3: to Delete an element at your specified location." << endl;
			cout << "Enter 4: to print the elements currently contained in the array." << endl;
			cout << "Enter 5: to show the size of the array." << endl;
			cout << "Enter 6: to clear the array and initialize it with new values, starting at the first element." << endl;
			cout << "Enter 7: to exit the program." << endl;
			cout << endl;
			cin >> userInput;
			cout << endl;

			switch (userInput)
			{

			case 1:

				cout << "Please enter the integer you wish to add to the end of the array:" << endl;

				cout << endl;

				cin >> itemToPass;

				cout << endl;

				add(itemToPass);

				break;

			case 2:

				cout << "Please enter the integer you wish to enter into the array:" << endl;

				cout << endl;

				cin >> itemToPass;

				cout << endl;

				cout << "Please enter the position in the array you wish to enter your integer:" << endl;

				cout << endl;

				cin >> indexToPass;

				cout << endl;

				insertItem(itemToPass, indexToPass);

				break;

			case 3:

				cout << "Please enter the value of the integer in the array you wish to delete:" << endl;

				cout << endl;

				cin >> itemToPass;

				cout << endl;

				deleteItem(itemToPass);

				break;

			case 4:

				if (count != 0) {

					cout << "Here are the values currently in the array:" << endl;
					cout << endl;

				}

				show();

				cout << endl;

				break;

			case 5:

				cout << "The current size of the array is: " << getCount() << "." << endl;

				cout << endl;

				break;

			case 6:

				cout << "You array has been refreshed and you may enter new values starting at index 1." << endl;

				cout << endl;

				clear();

				cout << endl;

				break;

			case 7:

				exit(0);

			default:

				break;
			}

		} while (userInput != 7);
}

ListType::ListType()
{

	count = 0;

}

ListType::~ListType()
{

	cout << "Destructor has been called." << endl;
	delete array;

}
