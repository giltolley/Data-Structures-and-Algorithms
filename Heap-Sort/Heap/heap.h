#include <cstdlib>
#include <iostream>
using namespace std;

template<class ItemType>
class HeapType
{
public:
	HeapType();
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	void Insert(ItemType item);
	void Swap(ItemType& first, ItemType& last);
	void printHeap(ostream& outs);
	void buildHeap();
	void HeapSort();
private:
	ItemType* elements;
	int numElements;
};

template<class ItemType>
HeapType<ItemType>::HeapType()
{
	elements = new ItemType[50];
	numElements = 0;
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = (root * 2) + 1;
	rightChild = (root * 2) + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent]< elements[bottom])
		{
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::Insert(ItemType item)
{
	elements[numElements] = item;
	ReheapUp(elements[0], elements[numElements]);
	numElements++;
}

template<class ItemType>
void HeapType<ItemType>::Swap(ItemType& first, ItemType& last)
{
	ItemType tempItem = first;
	first = last;
	last = tempItem;
}

template<class ItemType>
void HeapType<ItemType>::printHeap(ostream &outs)
{
	for (int counter = 0; counter < numElements; counter++)
	{
		outs << elements[counter] << ", ";
	}
}

template<class ItemType>
void HeapType<ItemType>::buildHeap()
{
	for (int index = numElements / 2 - 1; index >= 0; index--)
	{
		ReheapDown(index, numElements - 1);
	}
}

template<class ItemType>
void HeapType<ItemType>::HeapSort()
{
	buildHeap();

	//sort the array back using the heap
	for(int index = numElements-1; index >= 1; index--)
	{
		Swap(elements[0], elements[index]);
		ReheapDown(0, index-1);
	}
}