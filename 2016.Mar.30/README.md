Problem Description:
---	
	Detect and remove loop in a linked list. 

	Write a function detectAndRemoveLoop() that checks 
	whether a given Linked List contains loop and if loop 
	is present then removes the loop and returns true. 
	If the list doesn’t contain loop then returns false. 

	The website recommend to read the following post as prerequisite.

	Before trying to remove the loop, we must detect it. 
	Techniques discussed in the above post can be used to 
	detect loop. To remove loop, all we need to do is to 
	get pointer to the last node of the loop. For example, 
	node with value 5 in the above diagram. Once we have 
	pointer to the last node, we can make the next of this 
	node as NULL and loop is gone.
	
	We can easily use Hashing or Visited node techniques (
	discussed in the above mentioned post) to get the 
	pointer to the last node. Idea is simple: the very 
	first node whose next is already visited (or hashed) is 
	the last node.
	
	We can also use Floyd Cycle Detection algorithm to 
	detect and remove the loop. In the Floyd’s algo, the 
	slow and fast pointers meet at a loop node. We can use 
	this loop node to remove cycle. There are following two 
	different ways of removing loop when Floyd’s algorithm 
	is used for Loop detection.


Problem Solution:
---
	Since I have studied Floyd Cycle Detection algorithm 
	before, it was the frist thing pops into my head. 
	However, from what I can recall, the Floyd Cycle 
	Detection algorithm does not guaranteed the finding of 
	the last node in linked list, but merely the 
	determination of whether the list contains a loop or not. 

	Two Methods were introduced:

	- Simple way - one by one:

		1. Find a node inside of the loop
		2. Starting from the beginning of the list, for each
			element, cycle through the loop see if node->
			next is equal to that element.
		3 If so, make node->next = NULL;
		4 If not, continue to the next node in list.

	- Better way: 

		This method involves both Floyd's Cycle Detection algorithm and the algo used to finding the mth-to-last element in a linked list, which is another coding challange that I have done.

		Procedures are as follow:

			1. Using Floyd's Cycle Detection algo to find a	
				node inside of the loop
			2. Count the number of nodes, K, in the loop by	
				counting the number of iterations starting 
				from that node back to itself.
			3. Prepare two nodes, Head and Kth element from 
				Head. 
			4. Iterated till both of their nexts become the 
				same, then make the faster node's next NULL.

		The tricky part of this algorithm has to go to the counting the number nodes in the loop.

	- "Even better than better" way !?!?:

		I personally don't quite agree with this method 
		because I am quite convinced simply because it wouldn't always work, I think.

		But here it is:

			1. Using Floyd's Cycle Detection algo, find the 
				node in the loop.
			2. Assign the slow node to being the head.
			3. Iterate both slow and fast at the same pace 
				till fast->next == slow.
			4. assign fast->next = NULL

		Step 3 is the core of the alogrithm which is also the part I am really confused about.












