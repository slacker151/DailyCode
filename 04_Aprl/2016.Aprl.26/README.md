Problem Description:

	Finding the Lowest Common Ancestor in a BST

	Given the value of two nodes in a Binary Search 
	Tree, write a c program to find the Lowest Common 
	Ancestor(LCA). You may assume that both the values 
	exist in the tree.

Problem Solution:

	There are two ways to solving this problem. One 
	takes less space than the other. However, the time 
	complexity is around the same.

	Recursive:

		Starting from the root of the tree. We know 
		that if a value is smaller or equal to the 
		value of the root, it would be inserted to the 
		left side of the tree. Contrarilly, if the 
		value is larger than the value of the root, it 
		would be inserted on the right side of the root.

		Therefore, if one value is samller or equal to 
		the root and the other node is larger than 
		root, we can conclude that root is the LCA of 
		the two nodes. Now, the stopping conditions are 
		quite clear: if both nodes are NULL or if one 
		node is smaller or equal to the root and the 
		other is larger than the root. Note the root 
		does not necessarily represent the root of the 
		BST.

	Iterative: 

		Instead of calling the same function with its 
		left and right children, simply re-assign the 
		root pointer till one of the stopping 
		conditions is achieved.

