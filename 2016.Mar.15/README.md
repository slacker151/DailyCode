Problem 1 Description:

	Merge Sort:
		MergeSort is a divide and conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merg() function is used for merging two halves. The merge is key process that assumes that arr[l...m] and arr[m+1...r] are sorted and merges the two sorted sub-arrays into one.

Problem 1 Solution:

	Similar approach as to a binary search, however with recursive calls. Recursively divide the list into two sub arrays until there is only two elements left in the list. Then we sort the subarray1 and subarray2 ascendingly or descendingly. 


Problem 2 Description:
	
	Heap Sort:
		Heap Sort is a comparison based sorting technique bases on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

	A complete binary tree is a binray tree in which every level, except possibly the last, is completely filled, and all nodes are as far as possible.

	Binary heap is a complete binary tree where items are stored in a special order such that value in a parent node is greater than the values in its children nodes. The former is called as max heap and the later is called min head. The heap can be represented by binary tree or array. 

	Why array based representation fro binary heap?
		1. binary head is complete binary tree. 
		2. can be easily represented as arrary
		3. for Ith node, its left child is at I*2 + 1 and right child at I*2 + 2;

Problem 3 Description:

	Quick Sort:
		Quick sort is another divide and conquer sorting algorithm. It picks a pivot and partitions the given array around the pivot. There are many ways of picking the pivot point. But for this case, I am going to use the last element in the array.

		 