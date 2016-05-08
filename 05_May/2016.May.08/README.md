Problem Description:

	Count triplets with sum smaller than a given value.

	Given an array of distinct integers and a sum value. Find 
	count of triplets with sum smaller than given sum value.
	Expected Time Complexity is O(n^2).

	Example:

	Input : arr[] = {-2, 0, 1, 3}
        	sum = 2.
	Output : 2
	Explanation :  Below are triplets with sum less than 2
	               (-2, 0, 1) and (-2, 0, 3) 

	Input : arr[] = {5, 1, 3, 4, 7}
	        sum = 12.
	Output : 4
	Explanation :  Below are triplets with sum less than 4
	               (1, 3, 4), (1, 3, 5), (1, 3, 7) and 
	               (1, 4, 5)

Problem Solution:

	Clearly, there is a quite simple soultion which requires 
	O(n^3) Time complexity using 3 for-loops to iterate 
	through all possible combinations in the integer array.

	But that's not the point of this question...

	To increase the speed of the program, the most reasonable 
	and solution especially when with a list of randomly 
	ordered integer, sort the list first. Next, for each item 
	from index = 0 ... n - 2, find the sum of the two ends 
	the subarray and that item, if the sum is larger than the 
	given sum, than the ending index decrease by one. Else 
	the front++, the result += back - front. IMPORTANT!! the 
	reason reuslt += back - front is because the list is 
	sorted, since A + N already satisfies the condition sum, 
	everything in between them should also satisfy the 
	condition since the list is sorted.

