Problem Description:

	Generate all possible sorted arrays from alternate elements of two given two given sorted arrays.

	Given two sorted arrays A and B, generate all possible arrays such
	that first element is taken from A then from B then from A and so
	on in increasing order till the arrays exhausted. The generated 
	arrays should end with an element from B.


	For Example:

		A = {10, 15, 25}
		B = {1, 5, 20, 30}

		The resulting arrays are:
		  10 20
		  10 20 25 30
		  10 30
		  15 20
		  15 20 25 30
		  15 30
		  25 30

Problem Solution:

	This is a quite difficult question. 

	Important points:
		1. All arrays must be ended with an element from B.
		2. All arrays must start with an element from A.

	Well, I think that I have solved it without looking at the solution.

	My idea is to find all possible alternating array at its full length, 
	then print out all possible combinations from that array. To do that, 
	starting from the first element from A and last element from B, and 
	if the first element from B is smaller than A[i], then is means 
	that same result has already been generated already. 

