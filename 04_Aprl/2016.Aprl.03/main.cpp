#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

void Display(int *arr, int size)
{
	for (int i(0); i < size; ++i)
		std::cout << std::setw(4) << arr[i];
	std::cout << std::endl;
}

void ResevoirSampling(int *arr, int size, int k)
{
	if (k >= size)
		return;

	int reservoir[k];

	std::memcpy(reservoir, arr, sizeof(arr[0]) * k);
	
	Display(reservoir, k);

	srand(time(NULL));

	for(int i(k); i < size; ++i)
	{
		int j = rand() % (i + 1);
		
		if(j < k)
		{
			reservoir[j] = arr[i];
		}
	}

	Display(reservoir, k);
}

int main(int argc, char *argv[])
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(arr) / sizeof(arr[0]);

	int k(4);

	ResevoirSampling(arr, size, k);

	return 0;
}