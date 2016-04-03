Problem Description:

	Reverse a linked list in groups of given size. For example: 

	Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
	Output:  3->2->1->6->5->4->8->7->NULL. 

	Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
	Output:  5->4->3->2->1->8->7->6->NULL. 


Problem Solution:
	
	The first pops in my mind to use two pointers offsets the given size from each other. With special conditions along the way, for example, if the length of the linked list is smaller than the given size, as goes for if NULL node is hit. 

	However, there is a recursive way, which I have not figured out. 

	To be updated...