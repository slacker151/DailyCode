#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>

void  sortList(int *list, int size)
{
	for(int i(0); i < size - 1; ++i)
	{
		for(int j(i+1); j < size; ++j)
		{
			if(list[i] > list[j])
			{
				std::swap(list[i], list[j]);
			}
		}
	}
}

int countTriplets(int *arr, int size, int sum)
{
	int res(0);

	sortList(arr, size);

	for(int i(0); i < size - 2; ++i)
	{
		int j = i + 1;
		int k = size - 1;

		while(j < k)
		{
			if(arr[i] + arr[j] + arr[k] >= sum)
			{
				k --;
			}
			else
			{	
				res += k - j;
				j ++;
			}
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	int arr[] = {5, 1, 3, 4, 7};
	//sizeof() returns the number of chars in a variable
    int n = sizeof(arr) / sizeof (arr[0]);
    int sum = 12;
    std::cout << countTriplets(arr, n, sum) << std::endl;
	return 0;
}