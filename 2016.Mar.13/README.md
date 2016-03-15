Problem Description:

	Search an element in a sorted and rotated array.

	An element in a sorted arry can be found in O(log n) time via binary search. But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotate array in O(log n) time.


	Two Methods:

		1. More intuitive and broken down.
			First, find the pivot point in the array in O(log n) time. Next apply binary search on the two found sub-arrays. 

		2. More concise and sophisticated
			First, divide the array into two subarrays. The only possible situations are either the lower sub-array or upper sub-array is sorted. Next, the value we are searching for could be non-existant in the array, in the lower and sorted array, lower and non-sorted array, upper and sorted arrary, upper and non-sorted array. The base conditions are : length of the array is 0, and array[mid] == the element we are looking for. 
