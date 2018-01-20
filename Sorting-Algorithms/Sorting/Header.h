#include<cstdlib>
//PROTOTYPES
//
//
//NodeType Prototype (uses template)
template<class ItemType> 
struct NodeType
{
	//holds the info designated by the node
	ItemType info;

	//points to the next item in the QueueType
	NodeType<ItemType>* next;
};
//
//
//QueueType TEMPLATE CLASS
//
//
template<class ItemType> 
class QueueType
{
public:
	QueueType();
	~QueueType();
	void makeEmpty();
	void enqueue(ItemType);
	ItemType dequeue();
	bool isEmpty() const;
	bool isFull() const;
private:
	NodeType<ItemType>* rear;
	NodeType<ItemType>* front;
};
//
//
//
//
//Quicksort Prototype (uses template)

template<class ItemType>
class QuickSorter
{
public:
	void Split(ItemType values[], int first, int last, int& splitPoint);
	void QuickSort(ItemType values[], int first, int last);
	void Swap(ItemType& first, ItemType& last);
private:

};
//
//
//Mergesort Prototype
template<class ItemType>
class MergeSorter
{
public:
	void Merge(ItemType values[], int howMany, int leftFirst, int leftLast, int rightFirst, int rightLast);
	void MergeSort(ItemType values[], int howMany, int first, int last);
private:
		ItemType* tempArray;
};
//
//
//Radix Sorter
//
//
template<class ItemType>
class RadixSorter
{
public:
	void RadixSort(ItemType values[], int numPositions, int length);
	void CollectQueues(ItemType values[], QueueType<ItemType> dataPools[]);
private:
};
//CLASS DEFINITIONS
//
//

//
//
//
//
//QueueType definition (needs to be in header file)
template<class ItemType> 
QueueType<ItemType>::QueueType()
{
	rear = NULL;
	front = NULL;
}

template<class ItemType> 
void QueueType<ItemType>::makeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (front != NULL)
	{
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
	rear = NULL;
}

template<class ItemType> 
QueueType<ItemType>::~QueueType()
{
	makeEmpty();
}

template<class ItemType> 
bool QueueType<ItemType>::isFull() const
{
	NodeType<ItemType>* location;
	try
	{
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception)
	{
		return true;
	}
}

template<class ItemType> 
bool QueueType<ItemType>::isEmpty() const
{
	return (front == NULL);
}

template<class ItemType> 
void QueueType<ItemType>::enqueue(ItemType newItem)
{
	if (!isFull())
	{
		NodeType<ItemType>* newNode;

		newNode = new NodeType<ItemType>;
		newNode->info = newItem;
		newNode->next = NULL;

		if (rear == NULL)
		{
			front = newNode;
		}
		else
		{
			rear->next = newNode;		
		}
		rear = newNode;
	}
}

template<class ItemType> 
ItemType QueueType<ItemType>::dequeue()
{
	ItemType item;

	if (isEmpty())
	{
		throw std::string("Empty QueueType encountered");	
	}

	else
	{
		NodeType<ItemType>* tempPtr;

		tempPtr = front;
		item = front->info;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete tempPtr;
		return item;		
	}
}
//
//
//QUICKSORT TEMPLATE CLASS
//
//

template<class ItemType>
void QuickSorter<ItemType>::QuickSort(ItemType values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;

		Split(values, first, last, splitPoint);
		//values[first]...values[splitpoint-1] <= splitVal
		//values[splitPoint] = splitVal
		//values[splitpoint+1]...values[last] > splitVal

		QuickSort(values, first, splitPoint-1);
		QuickSort(values, splitPoint+1, last);
	}
}
template<class ItemType>
void QuickSorter<ItemType>::Split(ItemType values[], int first, int last, int& splitPoint)
{
	ItemType splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	while (first <= last)
	{
		onCorrectSide = true;
		while (onCorrectSide)
		{
			if(values[first] > splitVal)
			{
				onCorrectSide = false;
			}
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		}

		onCorrectSide = (first <= last);

		while (onCorrectSide)
		{
			if(values[last] <= splitVal)
			{
				onCorrectSide = false;
			}
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}
		}
		if (first < last)
		{
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	}
	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}//end split

template<class ItemType>
void QuickSorter<ItemType>::Swap(ItemType& first, ItemType& last)
{
	ItemType saveThis = first;
	first = last;
	last = saveThis;
}

template<class ItemType>
void MergeSorter<ItemType>::Merge(ItemType values[], int howMany, int leftFirst, int leftLast, int rightFirst, int rightLast)
{

	tempArray = new ItemType[howMany];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (values[leftFirst] < values[rightFirst])
		{
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	
	while (leftFirst <= leftLast)
	//copy remaining items from left half
	{
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast)
	//copy remaining items from right half
	{
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)
	{
		values[index] = tempArray[index];
	}
}

template<class ItemType>
void MergeSorter<ItemType>::MergeSort(ItemType values[], int howMany, int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, howMany, first, middle);
		MergeSort(values, howMany, middle + 1, last);
		Merge(values, howMany, first, middle, middle + 1, last);
	}
}

template<class ItemType>
void RadixSorter<ItemType>::RadixSort(ItemType values[], int numPositions, int length)
{
	QueueType<ItemType> dataPools[10];
	int whichQueue;

	for(int position = 1; position <= numPositions; position++)
	{
		for (int counter = 0; counter < length; counter++)
		{
			if (position == 1)
			{
				whichQueue = (values[counter] / 1) % 10;
			}
			else if (position == 2)
			{
				whichQueue = (values[counter] / 10) % 10;
			}
			else if (position == 3)
			{
				whichQueue = (values[counter] / 100) % 10;
			}
			else if (position == 4)
			{
				whichQueue = (values[counter] / 1000) % 10;
			}
			else if (position == 5)
			{
				whichQueue = (values[counter] / 10000) % 10;
			}
			else
			{
				whichQueue = 0;
			}
			
			dataPools[whichQueue].enqueue(values[counter]);
		}
		CollectQueues(values, dataPools);
	}
}

template<class ItemType>
void RadixSorter<ItemType>::CollectQueues(ItemType values[], QueueType<ItemType> dataPools[])
{
	int index = 0;
	ItemType item;

	for (int counter = 0; counter <= 9; counter++)
	{
		while (!dataPools[counter].isEmpty())
		{
			item = dataPools[counter].dequeue();
			values[index] = item;
			index++;
		}
	}
}
