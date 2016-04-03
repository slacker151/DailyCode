#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include <string>
#include <iomanip>

int Method1FindPivot(int *arr, int left, int right)
{
	if(right < left)
		return -1;
	if (left == right)
		return left;

	if(right > left)
	{
		int mid = left + (right - left) / 2;

		if(arr[mid] < arr[mid-1])
			return mid - 1;
		if(arr[mid] > arr[mid+1])
			return mid;

		if(arr[mid] > arr[left])
			return Method1FindPivot(arr, mid + 1, right);
		else
			return Method1FindPivot(arr, left, mid - 1);
	}
	return -1;
}

bool BS(int *arr, int key, int left, int right)
{
	if(right >= left)
	{
		int mid = left + (right - left) / 2;
		
		if(arr[mid] == key)
			return 1;
		if(arr[mid] > key)
			return BS(arr, key, left, mid-1);
		else
			return BS(arr, key, mid+1, right);
	}
	return 0;
}

bool Method1Search(int *arr, int key, int left, int right)
{
	int pivot = Method1FindPivot(arr, left, right);
	
	if(pivot == -1) // no rotation
	{
		return BS(arr, key, left, right);
	}
	else // with rotation
	{
		bool sub1 = BS(arr, key, left, pivot);
		bool sub2 = BS(arr, key, pivot+1, right);

		return sub1 || sub2;
	}
}

bool Method2Search(int *arr, int key, int left, int right)
{
	if(right < left)
		return 0;

	int mid = left + (right - left) / 2;

	if(arr[mid] == key)
		return 1;

	if(arr[mid] > arr[left])
	{
		if(key > arr[left] && key < arr[mid])
			return Method2Search(arr, key, left, mid - 1);
		else
			return Method2Search(arr, key, mid + 1, right);
	}	

	if(key > arr[mid] && key < arr[right])
		return Method2Search(arr, key, mid + 1, right); 

	return Method2Search(arr, key, left, mid - 1);
}

int main(int argc, char *argv[])
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int key (1);

	std::cout << (Method1Search(arr, key, 0, size-1) ? ("Found") : ("Doesn't exist")) << std::endl;
	std::cout << (Method2Search(arr, key, 0, size-1) ? ("Found") : ("Doesn't exist")) << std::endl;

	return 0;
}