#pragma once

#include "stdafx.h"

using namespace std;

//class prototypes
struct RecordRecord
{
	string artist;

	string title;

	int yearReleased;

	RecordRecord* next;
};

class RecordList
{
public:
	RecordList();

	bool isFull() const;

	int getLength() const;

	void retrieveItem(string& artist, string& title, int& year);

	void makeEmpty();

	void insertItem(string artist, string title, int year);

	void deleteItem(string artist, string title, int year);

	void resetList();

	void getNextItem(string& artist, string& title, int& year);

	vector<string> printList() const;

private:
	int length;

	RecordRecord* listData;

	RecordRecord* currentPos;

};