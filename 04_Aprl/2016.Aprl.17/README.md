Problem Description:

	Maximum Path Sum of a Binary Tree.

	Given a binary tree, find the maximum path sum. The path 
	may start and end at any node in the tree. This also 
	includes that some node value may be negative.

Problem Solution:

	Upon a naive approach and false assumption that the path 
	has to include the root of the tree. I used recursion to 
	figured out the one path from root that has the maximum 
	sum. However, if the root has a value of INT_MIN, the 
	path with maximum path would not even make any sense, 
	would it? As well as the path can go through the root 
	having maximum path of both children of the root. 
	Therefore, the things we need to check for: which child 
	has the maximum value? if the visiting node is the root, 
	then does the path that connects both of its children 
	yields the maximum path? 
	
