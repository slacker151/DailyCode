Problem Description:

	Convert array into Zig-Zag fashion

	Given an array of distint elements, rearrange the 
	elemnts of array in zig-zag fashion in O(n) time. The 
	converted array should be in form a < b > c < d > e < f

	Example:

		Input:  arr[] = {4, 3, 7, 8, 6, 2, 1}
		Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

		Input:  arr[] =  {1, 4, 3, 2}
		Output: arr[] =  {1, 4, 2, 3}

Problem Description:

	Simple Solution = O(nlogn).

	1. Sort the list of integer
	2. swap pairs of numbers other than the first number

	Efficient Solution = O(n).

	1. Using a for-loop to iterate from 0 -> n-2 of the list.
	2. For each cycle, it decide whether swaping L[i] & 
		L[i+1] or not depending on a boolean flag, which 
		alternates its value after each iteration