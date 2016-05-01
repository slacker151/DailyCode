Problem Description:

	Given perfect binary tree, reverse the alternate level nodes of the 
	binary tree.

	For example:

	Given tree: 

               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
       h  i j  k l  m  n  o 

	Modified tree:

  	      	   a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h 


Problem Solution:

	Two methods:

	LevelOrder Traversal:

		Since the requirement specify a perfect binary tree, 
		therefore, I can derive the number of elements at each tree 
		depth, which is 2 to the power of the depth of the tree.

		Now, I could firstly do a level-order and store the element 
		values in an array. Next, reverse partial strings within the 
		array with the std::swap() function. For the ease of array 
		manipulation, I should probably use a vector or an array.

	InOrder Traversal:

		This second method involves recording all the data values of 
		odd-level nodes and reverseing the container. Lastly, re-assign 
		the values back to the nodes in the same order. 

		It is important to note that sometimes memory reallocation of 
		nodes might not be the best way to go. Try re-assigning node
		values instead.
