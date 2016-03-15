#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <assert.h>
#include <iomanip>
#include <string>
#include <ctime>

void BubbleSort(int* arr, int size, bool order /*0=Ascending; 1=Descending*/)
{
	for(int i(0); i < size; ++i)
	{
		bool swapping(false);

		for(int j(0); j < size - i - 1; ++j)
		{
			if(order == true)
			{
				if(arr[j] < arr[j+1])
				{
					std::swap(arr[j], arr[j+1]);
					swapping = true;
				}
			}
			else if(order == false)
			{	
				if(arr[j] > arr[j+1])
				{
					std::swap(arr[j], arr[j+1]);
					swapping = true;
				}
			}
		}

		if(!swapping) // sorted
			break;
	}
}


int main(int argc, char * argv[])
{
	int arr[] = {2,3,1,5,34,123,11,2,1,23};
	int size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, size, 0);

	for (int i(0); i < size; ++i)
	{
		std::cout << std::setw(4) << arr[i];
	}

	std::cout << std::endl;

	return 0;
}