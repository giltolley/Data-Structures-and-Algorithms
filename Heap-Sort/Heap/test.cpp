#include "heap.h"
#include <iostream>
int main()
{
	char choice;
	int item;
	bool exit = false;
	HeapType<int> myHeap;

	while (!exit)
	{
		cout << "Heap Sort Algorithim" << endl;
		cout << "Press I to insert an item into the array" << endl;
		cout << "Press S to sort and display" << endl;
		cout << "Press X to exit" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 'X':
		case 'x':
			exit = true;
			break;
		case 'S':
		case 's':
			cout << endl;
			cout << "Before: ";
			myHeap.printHeap(cout);
			cout << endl;
			myHeap.HeapSort();
			cout << "After: ";
			myHeap.printHeap(cout);
			cout << endl;
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case 'I':
		case 'i':
			cout << "Please enter the item to be inserted: ";

			// Catch the variable in a temp INT for type-checking
			int x;
			cin >> x;
			while (cin.fail()) {
				cout << "Error: Please enter a valid Integer:" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x;
			}

			// Once we're sure we have an integer, add it to the Heap
			item = x;
			myHeap.Insert(item);
			cout << endl;
			cout << item << " was inserted" << endl;
			cout << endl;
			cout << "Current Heap: ";
			myHeap.printHeap(cout);
			cout << endl;
			system("pause");
			system("CLS");
			break;
		}//end switch
	}//end while
	return 0;
}//end main