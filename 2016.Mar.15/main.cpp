#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include <string>
#include <ctime>

void Merge(int *arr, int left, int mid, int right)
{
	int LSize(mid - left + 1);
	int USize(right - mid);
	int L[LSize];
	int U[USize]; // right - (mid + 1) + 1 = right - mid

	for(int i(0); i < LSize; ++i)
	{
		L[i] = arr[left+i];
	}
	for(int i(0); i < USize; ++i)
	{
		U[i] = arr[mid+1+i];
	}

	int i(0);
	int j(0);
	int k(left);

	while(i < LSize && j < USize)
	{
		if(L[i] <= U[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = U[j];
			j++;
		}
		k++;
	}

	while(i < LSize)
	{
		arr[k] = L[i];
		k++;
		i++;
	}

	while(j < USize)
	{
		arr[k] = U[j];
		k++;
		j++;
	}
}

void MergeSort(int *arr, int left, int right)
{
	if(right > left)
	{
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		Merge(arr, left, mid, right);
	}
}

typedef struct Heap
{
	int size;
	int *a;
}Heap;

void maxHeapify(Heap* H, int index)
{
	int root = index;  // Initialize largest as root
    int left = index * 2 + 1;  // left = 2*idx + 1
    int right = index * 2 + 2; // right = 2*idx + 2
 
    // See if left child of root exists and is greater than
    // root
    if (left < H->size && 
        H->a[left] > H->a[root])
        root = left;
 
    // See if right child of root exists and is greater than
    // the root so far
    if (right < H->size && 
        H->a[right] > H->a[root])
        root = right;
 
    // Change root, if needed
    if (root != index)
    {
        std::swap(H->a[root], H->a[index]);
        maxHeapify(H, root);
    }

    return;
}

Heap* CreateAndBuildHeap(int *arr, int size)
{
	Heap *maxHeap = new Heap;
	maxHeap->a = arr;
	maxHeap->size = size;

	for (int i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

void HeapSort(int *arr, int size)
{
	Heap *maxHeap = CreateAndBuildHeap(arr, size);

	while(maxHeap->size > 1)
	{
		// This is an ascending order
		std::swap(maxHeap->a[0], maxHeap->a[maxHeap->size - 1]);
		maxHeap->size--;
		maxHeapify(maxHeap, 0);
	}
}

int Partition(int *arr, int low, int high)
{
	int pivot = arr[high]; //pivot value;
	int i = low-1;

	for(int j(low); j <= high - 1; ++j)
	{
		if(arr[j] < pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i+1], arr[high]);
	return i + 1;
}

void QuickSort(int *arr, int low, int high)
{
	if(high > low)
	{
		int pivot = Partition(arr, low, high);

		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int size = sizeof(arr) / sizeof(arr[0]);

	// MergeSort(arr, 0, size-1);
	// HeapSort(arr, size);
	QuickSort(arr, 0, size - 1);

	for(int i(0); i < size; ++i)
	{
		std::cout << std::setw(4) << arr[i];
	}	

	std::cout << std::endl;
	return 0;
}