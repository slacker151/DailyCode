Problem Description:

	Bottom View of a binary tree.

	Given a binary tree, we need to print the bottom view from left to right. A node x is there in output if x is the bottonmost node at it horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minux 1, and that of right child is horizontal distance of x plus 1.

	For example:

	                  20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14

     	output: 5, 10, 3, 14, 25


     	If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. 

     	              20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10    14 

        output: 5, 10, 4, 14, 25

Problem Solution:

	This is a hard question, I did not figure it out...