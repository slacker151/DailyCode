Problem Description:

	Remove Nodes on root to leaf paths of length < K.

	Given a binary tree and number k, remove all nodes that lie only on root to leaf paths of length sammler than k. If a node X lies on multiple root-to-leaf paths and if any of the paths has path length >= l, then X is not deleted from binary tree. In other words a node is deleted if all paths going through it have lengths smaller than k.

Problem Solution:

	The idea here is to use post order traversal of the tree. Before removing a node we need to check that all the children of that node in the shorter path are already removed.

	There are 2 cases:
	i) This node becomes a leaf node in which cast it needs to be deleted.
	ii) This node has other child on a path with path length >= k. In that case it needs not to be delete.