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
		cout << "Press S to sort and exit" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;

		switch (choice)
		{
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
			exit = true;
			break;
		case 'I':
		case 'i':
			cout << "Please enter the item to be inserted: ";
			cin >> item;
			myHeap.Insert(item);
			cout << endl;
			cout << item << " was inserted" << endl;
			myHeap.printHeap(cout);
			cout << endl;
			cout << endl;
			break;
		}//end switch
	}//end while
	return 0;
}//end main