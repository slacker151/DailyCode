#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <string>
#include <utility>
#include <map>
#include <limits.h>

bool IsSorted(int *arr, int size)
{
	bool resultA(true);
	int ascending(INT_MIN);
	bool resultD(true);
	int descending(INT_MAX);

	for(int i(0); i < size; ++i)
	{
		if(ascending > arr[i] && resultA == true)
		{	
			resultA = false;
		}
		else
		{
			ascending = arr[i];
		}
		if(descending < arr[i] && resultD == true)
		{
			resultD = false;
		}
		else
		{
			descending = arr[i];
		}
	}

	return resultA || resultD;
}

bool BS(int *arr, int ele, int left, int right)
{
	if(right >= left)
	{
		int mid = left + (right - left) / 2;

		if(arr[mid] == ele)
			return 1;
		
		if(mid > arr[mid])
			return BS(arr, ele, left, mid - 1);
		else
			return BS(arr, ele, mid + 1, right);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int arr[] = {2, 3, 5, 8, 25, 45, 676, 3432};
	int size = sizeof(arr) / sizeof(arr[0]);

	if(IsSorted(arr, size))
	{
		std::cout << (BS(arr, 676, 0, size-1) ? ("Found") : ("Doesn't exist")) << std::endl;	
	}

	return 0;
}






