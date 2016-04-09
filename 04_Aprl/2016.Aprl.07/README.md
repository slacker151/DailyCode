Problem Description:

	A disjoint-set data structure that keeps track of a set of
	elements partitioned into a number of disjoint (non-overlapping
	) subsets. A union-find algorithm is an algorithm that 
	performs two useful operations on such a data structure:

	Find: 
		Determine which subset a particular element is in. This
		can be used for determining if two elements are in the 
		same subset.

	Union: 
		Join two subsets into a single subset.

	In this post, we will discuss an applicationi of Disjoint Set 
	Data Structure. The application is to check whether a given 
	graph contains a cycle or not.


Problem Solution:

	Union-find algorithm can be used to check whether an 
	undirected graph contains cycle or not. Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes that graph doesn't contain any self-loops.

	Find(int *parent, int vertex): if vertex is not linked to another vertex.

	Union(int *parent, int x, int y): find the toppest unlinked vertex for both vertices, and then assign parent[old head vertex] = graph[new head vertex]. 

	
	
