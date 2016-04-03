#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include <limits.h>

int Partition(int *arr, int left, int right)
{
	int pivot = arr[right];
	int i = left;

	for (int j(left); j <= right - 1 ; ++j)
	{
		if(arr[j] <= pivot)
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[right], arr[i]);
	return i;
}

int KthSmallest(int *arr, int low, int high, int k)
{
	if(k >= 0 && k <= (high - low))
	{
		int pivot = Partition(arr, low, high);

		if(pivot == k)
			return arr[pivot];
		if(pivot > k)
			return KthSmallest(arr, low, pivot - 1, k);

		return KthSmallest(arr, pivot + 1, high, k - pivot - 1);
	}
	else
	{
		return arr[low + k];
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	std::cout << KthSmallest(arr, 0, size-1, k - 1) << std::endl;

	return 0;
}