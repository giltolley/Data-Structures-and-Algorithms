// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"


RecordList::RecordList()
{
	length = 0;
	listData = NULL;
}

void RecordList::insertItem(string artist, string title, int year)
{
	RecordRecord* location;

	location = new RecordRecord;

	location->artist = artist;
	location->title = title;
	location->yearReleased = year;

	location->next = listData;

	listData = location;

	length++;
}

bool RecordList::isFull() const
{
	RecordRecord* location;
	try
	{
		location = new RecordRecord;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int RecordList::getLength() const
{
	return length;
}

void RecordList::makeEmpty()
{
	RecordRecord* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

void RecordList::retrieveItem(string& artist, string& title, int& year)
{
	bool moreToSearch;
	RecordRecord* location;
	bool found = false;

	location = listData;
	moreToSearch = (location != NULL);

	while (moreToSearch == true && found == false)
	{
		if (artist == location->artist && title == location->title && year == location->yearReleased)
		{
			found = true;
			artist = location->artist;
			title = location->title;
			year = location->yearReleased;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
}

void RecordList::deleteItem(string artist, string title, int year)
{
	RecordRecord* location = listData;
	RecordRecord* tempLocation;

	if (artist == location->artist && title == location->title && year == location->yearReleased)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (!(artist == (location->next)->artist && title == (location->next)->title && year == (location->next)->yearReleased))
		{
			location = location->next;
		}

		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

void RecordList::resetList()
{
	currentPos = NULL;
}

void RecordList::getNextItem(string &artist, string &title, int &year)
{
	if (currentPos == NULL)
	{
		currentPos = listData;
	}
	else
	{
		currentPos = currentPos->next;
	}
	artist = currentPos->artist;
	title = currentPos->title;
	year = currentPos->yearReleased;
}

vector<string> RecordList::printList() const 
{
	vector<string> returnData;

	string currentAlbum;

	RecordRecord* listPos;

	//listPos = currentPos;

	if (currentPos == NULL)
	{
		listPos = listData;
	}
	else
	{
		listPos = currentPos->next;
	}

	int listLength = getLength();

	while (listLength != 0)
	{
		currentAlbum = listPos->artist;
		currentAlbum += " -- ";

		currentAlbum += listPos->title;
		currentAlbum += " :: ";

		currentAlbum += to_string(listPos->yearReleased);
		currentAlbum += "\n";

		returnData.push_back(currentAlbum);

		listLength--;

		listPos = listPos->next;
	}

	return returnData;
}