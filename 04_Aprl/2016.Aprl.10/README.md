Problem Description:

	Given a connected and undirected graph, a spanning tree of that 
	graph is subgragh that is a tree and connects all the vertices 
	together. A signle graph can have many different spanning tree. 
	A minimum spanning tree or minimum weight spanning tree for a 
	weighted, connected and undirected graph is a spannning tree 
	with weight less than or equal to the weight of every other 
	spanning tree. The weight of a spanning tree is the sum of 
	weights given to each edge of the spanning tree.

	How many edges does a minimum spanning tree has?
		V - 1 edges where V is the number of vertices in the given graph.

Problem Solution:

	Below are the steps for finding MST using kruskal's algo:

	1. Sort all the edges in a ascending order of their weight
	
	2. Start from the lowest weighing edge, check if it forms a 
	cycle with the spanning tree. If cycle is not formed, include 
	this edge. Else, discard it.

	3. Repeat step 2 until there are V - 1 number of edges in the 
	result edge collection. This is because of the theory mention 
	earlier - a MST should have all vertices connected and V - 1 
	number of edges with V number of vertices.
