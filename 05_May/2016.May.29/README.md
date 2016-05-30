Q1 Description

	Given that integers are read froma data stream, find median of elements read so for a efficient way. For simplicity assume ther are no dulplicates.

	Make it clear, when the input size if odd, we take the middle element of sorted data. If the input size is eve, we pick average of middle two elements in sorted stream.

	Note:
		output is effecitve median of integers read from the stream so far. Such an algorithm is called onlien algorithm. Any algorithm that can guarantee outptu of i-elements after processing i-th element, is called online-algorithm.
	
Q1 Solution

	Method 1: 
		1. Sort list using insertion sort
		2. Return result base on the odd/even property the list

	Method 2:
		Using a binary tree, with a max heap on its left side representing elements that are less than effective median and a min heap on the right side representing elements that are greater than effective median. After processing an incoming element, the number of elements in heaps differ utmost by 1 element. when both heaps contain same number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective median from the root of heap containing more elements.




Q2 Description
	
	The problem is to count all the possible path from top-left to bottom-right of a MxN matric with the constraints that each cell you can either move only to right or down.

Q2 Solution
		
	I think this question can be solved using recursion. which can then be optimized using DP's memoization. improving the time complexity from the previous exponential to square.




Q3 Description

	Given a large text file, find an efficient algorithm to find the least distance between any two given words.

Q3 Solution

	Using my method, which require a record of latest index of both words in text and a leastDistance. Upon every occurance of either words, update the index and leastDistance. After going through the whole text, the leastDistance should contain the minimum distance between the word pair.

	The solution that the poster suggests is to hash all occurances of the two words within a list, after that, for each occurance of one word, do a binary search on the other in the second list with time complexity of O(logn), going through the whole list comes to time complexity of O(nlogn). 
	which is not bad.



Q4 Description
	
	Given the background of how autocorrect feature on phone pad work, explaining that the probabilty of the autocorrect word would be greater than the typed word. With an algorithm for finding the most probable word of length n that can occur given that there are m possible characters. The probability that a word can occur is given as: P(1st letter) * P(2nd letter given that 1st has been pressed already) * P(2nd) * P(3rd letter given that 2nd letter has been pressed already). All values of the equation has been given. Solve the equation.

Q4 Solution
	To solve this problem, use DP's memoization to hash intermedieate results for later use.







