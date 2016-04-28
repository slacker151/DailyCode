Problem Description:

	Check if a BT is subtree of another BT

	Given two binray trees, check if the first tree is subtree of the second one. A subtree of a tree T is tree S consisting of a node in T and all of its descendants in T.

	THe subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

Problem Solution:

	There is a very straight forward method: for each node in the bigger tree, check if two trees are the same or not. This method has a time complexity of O(n^2). 

	However, there is a better solution: with time complexity of O(n). The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree. TRee S is a subtree of T if both inorder and preorder travesal of S are substrings of inorder and preorder of T respectively. Note that this assumes that there is no repeating nodes within the BTs.

	

