#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

void zigZag(int *arr, int size)
{
	bool flag(true);

	for(int i(0); i < size - 1; ++i)
	{
		if(flag)
		{
			if(arr[i] > arr[i+1])
				std::swap(arr[i], arr[i+1]);
		}
		else
		{
			if(arr[i] < arr[i+1])
				std::swap(arr[i], arr[i+1]);
		}
		flag = !flag;
	}
}

void printList(int *arr, int size)
{
	for(int i(0); i < size; ++i)
	{
		std::cout << std::setw(3) << arr[i];
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    //Before
    printList(arr, n);

    zigZag(arr, n);
    
    //After
    printList(arr, n);
	
	return 0;
}