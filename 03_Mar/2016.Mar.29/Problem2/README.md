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

	I only got to learning merge sort on linked list. I saw how easy it is to apply the merge sort on linked list as the Merge() does it job - firstly creates a new node, then check if either linked lists have ran out of elements to compare, if so, return the other linked list as result. If it has not reached the stopping condition, then for ascending order, we say if LL1->data <= LL2->data, then assign the newNode with the smaller data, and assign newNode->next with Merge(LL1->next, LL2); on the contrary, we do the same of LL2->data is smaller than LL1->data. 

	This is much easier than the typical preset array merge sort since everything is dynamically allocated the assigned, which avoids brute force assignments.

	However, with such an ease, there is a cerain tradeoff - having to figure out the two starting nodes of the sub linked lists efficiently using two nodes for traversing, one traverses twice as fast as the other one very much lowers the time complexity of the linked list traversal.









