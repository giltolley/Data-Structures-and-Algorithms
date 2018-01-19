#include "stdafx.h"
#include "LinkedList.h"

int main()
{
	string userInput;
	char choice;
	bool exit = false;
	RecordList myRecord;
	vector<string> listView;

	string art;
	string title;
	string year;

	while (exit != true)
	{

		cout << "+================================================+" << endl;
		cout << "+                                                +" << endl;
		cout << "+  Press A to add a Record to the Record Record  +" << endl;
		cout << "+  Press V to View the Record Record             +" << endl;
		cout << "+  Press Q to Quit                               +" << endl;
		cout << "+                                                +" << endl;
		cout << "+================================================+" << endl;
		getline(cin, userInput);

		if (userInput.length() == 0)
		{
			choice = 'X';
		}
		else
		{
			choice = userInput[0];
		}

		switch (choice)
		{
		case 'A':
		case 'a':
			cout << "Please enter the Artist name: ";
			getline(cin, art);
			cout << endl;
			cout << "Please enter the Title of the CD: ";
			getline(cin, title);
			cout << endl;
			cout << "What year was it released?: ";
			getline(cin, year);
			cout << endl;
			myRecord.insertItem(art, title, stoi(year));
			system("CLS");
			break;
		case 'V':
		case 'v':
			listView = myRecord.printList();
			cout << "Record List:";
			cout << endl;
			for (vector<string>::iterator it = listView.begin(); it != listView.end(); ++it)
				cout << ' ' << *it;
			cout << endl;
			break;
		case 'Q':
		case 'q':
			exit = true;
			break;
		case 'X':
		case 'x':
		default:
			cout << "No valid input detected...Please try again.";
			cout << endl;
		}
	}
	return 0;
}