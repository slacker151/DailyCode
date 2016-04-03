Problem Description:
	
	Given a singly linked list, write a function to delete a given node. Your function must follow following constraints: 
	1) It must accept pointer to the start node as first parameter and node to be deleted as second parameter
	2) It should not return pointer to the head node.
	3) It should not accept pointer to pointer to head node.


Problem Solution:
	
	Since we have a specific deleting pointer of type Node. The problem become really simple, we only need to figure out a solution to compare pointers. 

	First of all, we check wether the head == deletingNode, if yes, then head = head->next and delete the deletingNode.

	Second, with a while loop we can determine node->next == deletingNode or node->next == NULL, then we connect the previous node and next node of the deletingNode. Finally, we delete the deletingNode. Else if, we hit NULL, which is the end of the LL, this means that the deletingNode is not in the LL.
