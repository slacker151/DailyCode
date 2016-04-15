Problem Description:

	Tree: Find the minimum depth of a binary tree (BT)

Problem Solution:

	Sounds pretty straight forward. 

	Intuitive way: (DFT)

		Using recursion to step down to every leaf to determine the lowest depth of the tree. 

		if(root == NULL)
			return 0;

		int leftLength = 1 + GetMinDepth(root->left);
		int rightLength = 1 + GetMinDepth(root->right);

		return std::min(leftLength, rightLength);

	Better way: (BFT)

		Using similar technique as the BFT in the graph theory BFT, using a queue to record the children nodes, and the depth. When encounter a node, if both of its children are NULL, then we return the depth of it. This guarentees that the first node we find is going to be with the minimum depth in that tree.

