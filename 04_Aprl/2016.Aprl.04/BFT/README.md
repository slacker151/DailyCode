Problem Description:

	Breadth First Traversal for a graph.

	Breadth first travesal for a graph is similar to breadth first 
	traversal of a tree. The only catch here is, unlike trees, 
	graphs may contain cycles, so we may come to the same node 
	again. To avoid processing a node more than onec, we use a 
	boolean visited array. For simplicity, it is assumes that all 
	vertices are reachable from the starting vertex. Breadth, 
	meaning the graph is traversed level by level.

Problem Solution:

	Given a vertex in the graph, determine the BFT. Follow the 	
	following procedures:
	
	1. Create a bool[] with size of NumOfVertices
	2. Create a queue list and push the starting point in
	3. While the queue is not empty, pop and display the vertice
	4. If the vertice has never been visited from the bool[] then,
	5. For each vertice, push its linked vertices into the queue
	
	