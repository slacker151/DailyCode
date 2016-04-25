Problem Description:

	Top view of a binary tree.

	Given a binary tree, print the top view of it. The output nodes can be printed in any order. Expected time complexity is O(n). 

	A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left hildof a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Problem Solution:

	Using both breadth first traversal and hash table, for each node of the tree, we create a QItem with that node and its horizontal distance from the root (with root having 0), left child of a node is its parents' horizontal distance - 1, right child of a node is its parents' horizontal distance + 1. If the hash table at key horizontal distance is empty, then push the node->data into the hash and print the node->data. Else, do nothing.

	




















