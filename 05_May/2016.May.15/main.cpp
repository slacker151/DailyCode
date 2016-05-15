#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <limits>

class MinHeap
{
public:
	MinHeap();
	MinHeap(int);
	~MinHeap();

	int getMin();
	int extractMin();
	void insertKey(int key);
	void deleteKey(int key);
	void decreaseKey();
	void minHeapify(int index);

private:
	int* arr;
	int capacity;
	int heapSize;
};

MinHeap::MinHeap()
{
	//Default Ctor
}

MinHeap::MinHeap(int size)
	: capacity(size)
	, heapSize(0)
	, arr(new int [size])
{}

MinHeap::~MinHeap()
{
	delete [] arr;
}

int MinHeap::getMin()
{
	if(heapSize != 0)
		return arr[0];
	else
		return INT_MIN;
}

int MinHeap::extractMin()
{
	if(heapSize <= 0)
	{
		return INT_MIN;
	}
	if(heapSize-- == 1)
	{
		return arr[0];
	}

	int root = arr[0];
	std::swap(0, heapSize);
	minHeapify(0);

	return root;
}

void MinHeap::insertKey(int key)
{
	if(heapSize == capacity)
	{
		std::cerr << "Overflow \n"; return;
	}

	heapSize++;
	int index = heapSize - 1;
	arr[index] = key;

	while(index != 0 && arr[index] < arr[(index - 1) / 2])
	{
		std::swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void MinHeap::deleteKey(int key)
{

}

void MinHeap::decreaseKey()
{

}

void MinHeap::minHeapify(int index)
{
	int left = arr[index * 2 + 1];
	int right = arr[index * 2 + 2];
	int smallest = index;

	if(left < heapSize && arr[index] > arr[left])
		smallest = left;
	if(right < heapSize && arr[left] > arr[right])
		smallest = right;

	if(smallest != index)
	{
		std::swap(arr[index], arr[smallest]);
		minHeapify(smallest);
	}
}	


int main(int argc, char const *argv[])
{
	MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    
    h.decreaseKey(2, 1);
    cout << h.getMin();
	
	return 0;
}