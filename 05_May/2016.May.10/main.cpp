#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <vector>

void PrintArrays(std::vector<int> superArray)
{
	int counter(1);

	while(counter * 2 <= superArray.size())
	{
		for(int i(0); i < counter *2; ++i)
		{
			std::cout << std::setw(4) << superArray[i];
		}
		std::cout << std::endl;
		counter++;
	}
}

int GetNextLargerThan(int* list, int size, int from, int value)
{
	int index(-1);

	for(int i(from); i < size; ++i)
	{
		if(list[i] > value)
		{
			index = i;
			break;
		}
	}

	return index;
}

void GenerateArrays(int *A, int* B, int ASize, int BSize)
{
	std::vector<int> res;

	for(int i(0); i < ASize; ++i)
	{
		//Always start with an element from A[]
		res.clear();
		res.push_back(A[i]);

		for(int j(BSize - 1); j >= 0; --j)
		{
			//Checking for repeation
			if(B[j] < A[i])
				break;

			//Initializing starting indices
			int nextAIndex(i);
			int nextBIndex(j);

			while(1)
			{	
				nextBIndex = GetNextLargerThan(B, BSize, nextBIndex, A[nextAIndex]);
				if(nextBIndex == -1)
					break;
				res.push_back(B[nextBIndex]);

				nextAIndex = GetNextLargerThan(A, ASize, nextAIndex, B[nextBIndex]);
				if(nextAIndex == -1)
					break;
				res.push_back(A[nextAIndex]);
			}	

			//Print all possible combinations of arrays
			PrintArrays(res);

			//Start a new array
			res.clear();
			res.push_back(A[i]);
		}
	}	
}

int main(int argc, char const *argv[])
{
	int A[] = {10, 15, 25};
    int B[] = {1, 5, 20, 30};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    
    GenerateArrays(A, B, n, m);

	return 0;
}