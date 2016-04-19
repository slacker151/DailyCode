Problem Description:

	Check if a given array can repreasent Preorder Traversal of BST.

	Reminder:
	Pre-Order Traversal: this, left, and right. 

	BST is a binary tree that ensures that the left child of a node is always less or equal to that node and the right child of the node is always larger than the node. 

	Now given an array of numbers, the first number for sure is the root of the tree, the number after that should supposedly be the left child of the root. However if that number is larger than the root, then it means that number is the right child of the root. 

Problem Solution:

	Therefore, the solution that I can think of:
		Step 1: Initialize a BST root.
		Step 2: Inserting elements from the array to the tree
				If parent node at which the insertion occurs has leftChild == NULL && rightChild != NULL, then it is not a valid for a Pre-Order Traversal. 

	I figured it out... Good job to me

