#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
	bool exit = false;
	char choice;
	QuickSorter<int> myQS;
	MergeSorter<int> myMS;
	RadixSorter<int> myRS;
	int highest = 0;
	double numPositions = 0;
	int passMe = 0;
	int amount = 0;
	int* values;
	

	while(!exit)
	{
		cout << "Gil's Random Sorter Program With No Real Point" << endl;
		cout << "1) Quick Sort" << endl;
		cout << "2) Merge Sort" << endl;
		cout << "3) Radix Sort" << endl;
		cout << "4) Fill Array With Random Numbers" << endl;
		cout << "5) Display Array" << endl;
		cout << "Please Make A Selection: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			myQS.QuickSort(values, 0, amount - 1);
			cout << endl;
			cout << "Should be sorted now..." << endl;
			cout << endl;
			break;
		case '2':
			myMS.MergeSort(values, amount, 0, amount - 1);
			cout << endl;
			cout << "Should be sorted now..." << endl;
			cout << endl;
			break;
		case '3':
			numPositions = highest / 100;
			if (numPositions < 10)
			{
				passMe = 3;
			}
			else if (numPositions >= 10 && numPositions < 100)
			{
				passMe = 4;
			}
			else if (numPositions >= 100 && numPositions < 1000)
			{
				passMe = 5;
			}

			myRS.RadixSort(values, passMe, amount);
			cout << endl;
			cout << "Should be sorted now..." << endl;
			cout << endl;
			break;
		case '4':
			cout << "Please enter highest possible random value: ";
			cin >> highest;
			cout << "Please enter how many numbers to make: ";
			cin >> amount;
			cout << endl;
			values = new int[amount];

			for(int i = 0; i < amount; i++)
			{
				int randNum = (rand()%highest) + 1;
				values[i] = randNum;
			}
			cout << endl;
			cout << "Array Filled" << endl;
			cout << endl;
			break;
		case '5': 
			cout << endl;
			for(int i = 0; i < amount; i++)
			{
				cout << values[i] << endl;
			}
			cout << endl;
			break;
		default:
			cout << endl << "Not a valid choice, please choose again." << endl;
		}
	}
	return 0;
}