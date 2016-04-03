#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>
#include <string>
#include <algorithm>
#include <limits.h>

void printClosest(int *arr, int size, int val)
{
	int min_diff(INT_MAX);
	int mindex1(0);
	int mindex2(0);

	for(int i(0); i < size - 1; ++i)
	{
		for(int j(i+1); j < size; ++j)
		{
			int temp = arr[i] + arr[j];
			int result = std::abs(val - temp);
			if(result < min_diff)
			{
				min_diff = result;
				mindex1 = i;
				mindex2 = j;
			}
		}
	}

	std::cout << "The two elements are: " <<
				arr[mindex1] << " and " << 
				arr[mindex2] << std::endl;
}

int main(int argc, char *argv[])
{
    int arr[] =  {10, 22, 28, 29, 30, 40};
    int x = 54;
    int n = sizeof(arr)/sizeof(arr[0]);
    printClosest(arr, n, x);
    return 0;
}