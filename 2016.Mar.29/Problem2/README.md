Problem Description:

	Given two linked list, create union and intersection lists that contains the union and intersection of the elements in the lists. The order in the output list does not matter.

	For example:

		Input:
			List1: 10->15->4->20
			lsit2:  8->4->2->10
		Output:
			Intersection List: 4->10
			Union List: 2->8->20->4->15->10

Problem Solution:
	
	The first and simplest method:

		Intersection list:
			For every element in LL1, search for it in LL2. If it is found, delete all nodes of same value in both linked lists, then insert a node with that value to the intersection list.

		Union:
			After figuring out the intersection list, pipe everything left from both LL1 and LL2 to the union list. 


	Using Merge Sort:

		Merge sort is often preferred for sorting a linked list.

		After sorting both lists which costs O(nlog(n)) and O(mlog(m)), we can use binary search twice for intersection and union lists. The time complexity is still faster than Method1.

	Using Hash:

		Although, this method is way faster than any other methods, the memory cost could be quite pricy.

	For the purpose of learning something new, I will proceed with the second method which is the merge sort way.