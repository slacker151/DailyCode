Problem Description:

	Merge a linked list into another linked list at alternative positions.

	Given two linked list, insert the nodes of the second linked list into the first linked list at alernative positions.

	For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

	Constraints:
		1. Use of extra space is not allowed (Not allowed to create new nodes). 
		2. Insertions must be done in-place. 
		3. Expect the time complexity to be O(n), where n is number of elements in LL1.

Problem Solution:

	Since "The nodes of second list should only be inserted wher there are positions available", this means the iteration is dependented on LL1. 

	The trick is to get your head straight with how to point the nodes from LL2 to LL1 without deleting them. As well as, when LL1 has reached its end and LL2 is not empty yet, we need to append remove one more node from LL2 and append it to LL1 without attaching the rest of LL2 to LL1.

	