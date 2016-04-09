Problem Description:

	Prim's Minimum Spanning Tree

	It starts with an empty spanning tree. The idea is to maintain
	two sets of vertices. The first set contains the vertices 
	already included in the MST, the other set contains the 
	vertices not yet included. At every step, it considers all the 
	edges that connect the two sets, and picks the minimum weight 
	edge from these edges. After picking the edge, it moves the 
	other endpoint of the edge to the set containing MST.

	A group of edges that connects two set of vertices in a graph 
	is called cut in graph theory. So, at every step of Prim's 
	algoritm, we find a cut (of two sets, one contains the 
	vertices already included in MST and other contains rest 
	of the vertices), pick the minimum weight edge from the cut 
	and include this vertex to MST Set.

Problem Solution:

	How does Prim's Algorithm work?

	The idea behind Prim's algorithm is simple, a spanning tree means all vertices must be connected. So the disjoint subsets of vertices must be connected to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a minimum Spanning Tree.

	Prim's minimum spanning tree (MST) uses Dijkstra's shortest
	path finding algorithm.However, the difference between this 
	and a previous question - the shortest path between a source 
	vertext to every other vertices, is that we are not comparing 
	nor assign the sum between the connecting vertices but only 
	updating the lowest weight. Because of which, we need to 
	record the src vertex of the lowest weight in a seperate 
	container, so we know the full edge and full graph.