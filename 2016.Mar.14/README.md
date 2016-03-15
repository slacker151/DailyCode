Problem 1 Description:
	
	Bubble Sort : the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. 

	Example:
	
	First Pass:
	( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
	( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
	( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
	( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
	
	Second Pass:
	( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
	( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
	Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
	
	Third Pass:
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

Solution 1 Description:

	Clearly, there are array-length number of passes. For each pass, there are array-length - 1 number of comparisons(ascending and descending differences).

	two for-loops, comparisons, and swaps.

	Each iteration is going to figure out what the last element in the array is going to be. Since the algorithm, compares arr[0] and arr[1], then arr[1] and arr[2] ... till the end. The end element is always going to be either the largest or the smallest in the array. Therefore, we can do this for the last, second-last, third last, fourth last, and so on.

	However, if an array is already sorted, the algorithm would iterate regardless. To prevent this from happening, a boolean variable is used to determine whether a swap has occured. If not, it means that the array is sorted then we break. O(n^2)

Problem 2 Description:

	Insertion Sort: one of the simplest sorting algorithms out there. 

Solution 2 Description:
	
	I do not find this algorithm quite as intuitive as selection sort, which is my favorite goto O(n^2) sorting algorithm.


Problem 3 Description:

	Selection Sort: one of the simplest sorting algorithms out there. 

Solution 3 Description:
	
	This is in my opinion the most intuitive O(n^2) time complexity sorting algorithm.
	It just makes the most sense to me. 





