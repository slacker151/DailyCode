#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <limits>

void FirstMethod_sortList(int* arr, int size)
{
	for(int i(0); i < size - 1; ++i)
	{
		for(int j(i+1); j < size; ++j)
		{
			if(arr[j] < arr[i])
				std::swap(arr[j], arr[i]);
		}
	}		
}

void FirstMethod(int* arr, int size)
{	
	if(size <= 0)
	{
		std::cout << "Invalid list \n";
		return;
	}

	int* copyArr = new int[size];

	std::memcpy(copyArr, arr, size * sizeof(int));

	FirstMethod_sortList(copyArr, size);

	if(size % 2 == 0) // even
	{
		std::cout << static_cast<double>((copyArr[size/2] + copyArr[size/2-1]) / 2.0)
				  << std::endl;
	}
	else //odd
	{
		std::cout << copyArr[size / 2] << std::endl;
	}

	delete [] copyArr;
}

class Heap
{
public:
	~Heap()
	{
		if(A != NULL) delete [] A;
	}

	int GetTop()
	{
		if(currentHeapSize > 0)
		{
			return A[0];
		}
		else
		{
			return -1;
		}
	}

	int GetHeapSize()
	{
		return currentHeapSize;
	}

	void Insert(int data)
	{
		A[currentHeapSize] = data;
		Heapify(currentHeapSize);
		currentHeapSize++;
	}
	int Extract()
	{
		if(currentHeapSize <= 0)
			return INT_MAX;

		int top = A[0];
		std::swap(A[0], A[currentHeapSize-1]);
		currentHeapSize--;
		ToggleDown(0);

		return top;
	}

protected:
	Heap(int maxSize)
		: A(new int[maxSize])
		, currentHeapSize(0)	
	{};

	virtual void Heapify(int index) = 0;
	virtual void ToggleDown(int index) =0;

	int *A;
	int currentHeapSize;
};






class minHeap : public Heap
{
public:
	minHeap(int maxHeapSize)
		: Heap(maxHeapSize)
	{
		std::fill_n(A, maxHeapSize, INT_MAX);
	}

protected:
	virtual void Heapify(int index)
	{
		if(index == 0)
			return;

		int parentIndex = (index - 1) / 2; 

		if(A[index] < A[parentIndex])
		{
			std::swap(A[index], A[parentIndex]);
			Heapify(parentIndex);
		}	
		else
		{
			return;
		}
	}

	virtual void ToggleDown(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;

		if((left < currentHeapSize || right < currentHeapSize) 
			&& index < currentHeapSize)
		{
			int smallest = index;

			if(left < currentHeapSize && A[left] < A[index])
			{
				smallest = left;
			}
			if(right < currentHeapSize && A[right] < A[left])
			{
				smallest = right;
			}
			if(smallest != index)	
			{
				std::swap(A[index], A[smallest]);
				ToggleDown(smallest);
			}
		}
		else
		{
			return;
		}
	}
};






class maxHeap : public Heap
{
public: 
	maxHeap(int maxHeapSize)
		: Heap(maxHeapSize)
	{
		std::fill_n(A, maxHeapSize, INT_MIN);
	}

protected:
	virtual void Heapify(int index)
	{
		if(index == 0)
			return;

		int parentIndex = (index - 1) / 2; 

		if(A[index] > A[parentIndex])
		{
			std::swap(A[index], A[parentIndex]);
			Heapify(parentIndex);
		}	
		else
		{
			return;
		}
	}

	virtual void ToggleDown(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;

		if((left < currentHeapSize || right < currentHeapSize) 
			&& index < currentHeapSize)
		{
			int largest = index;

			if(left < currentHeapSize && A[left] > A[index])
			{
				largest = left;
			}
			if(right < currentHeapSize && A[right] > A[left])
			{
				largest = right;
			}
			if(largest != index)	
			{
				std::swap(A[index], A[largest]);
				ToggleDown(largest);
			}
		}
		else
		{
			return;
		}
	}
};




void SecondMethod_GetMedian(int val, int& median, Heap& left, Heap& right)
{
	if(left.GetHeapSize() > right.GetHeapSize())
	{
		if(val > median)
		{
			right.Insert(val);
		}
		else
		{
			right.Insert(left.Extract());
			left.Insert(val);
		}

		median = (left.GetTop() + right.GetTop()) / 2;
	}
	else if(left.GetHeapSize() == right.GetHeapSize())
	{
		if(val > median)
		{
			right.Insert(val);
		}
		else
		{
			left.Insert(val);
		}

		median = val;
	}
	else if(left.GetHeapSize() < right.GetHeapSize())
	{
		if(val > median)
		{
			left.Insert(right.Extract());
			right.Insert(val);
		}
		else
		{
			left.Insert(val);
		}

		median = (left.GetTop() + right.GetTop()) / 2;
	}
}

void SecondMethod(int* arr, int size)
{
	Heap* left = new maxHeap(size);
	Heap* right = new minHeap(size);

	int res(0);

	for(int i(0); i < size; ++i)
	{
		SecondMethod_GetMedian(arr[i], res, *left, *right);
	}

	std::cout << res << std::endl;

	delete left;
	delete right;
}

int main(int argc, char const *argv[])
{
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A) / sizeof(A[0]);
 
    //FirstMethod(A, size);
    SecondMethod(A, size);

	return 0;
}