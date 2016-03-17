Problem 1 Description:

	Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Problem 1 Solution:

	Off the top of my head, creating a min_diff and a hash table with min_diff key type.

	Turns out, I got it on the first try. It is very similar to the selection sort algorithm. However, keeping track of which pair has the least difference from the provided value. Obviously, comparing one sum at a time doesn't really require the Hash table.
	



Problem 2 Description:
	
	Given a linked list which is sorted, how will you insert another element into the LL in a sorted way.

Problem 2 Solution:

	This is a very basic LL problem. Assuming that the linked list in ordered ascendingly, my approach was to firstly check if the inserted value is smaller than the head->data, if so create new node with data and next to be the current head, then assign this new node to be the head. Next, I check whether the value is anywhere in between the nodes in the LL. If so, insert it. Lastly, if the inserted value is larger any of the value in the list, then make it the last element in the linked list.