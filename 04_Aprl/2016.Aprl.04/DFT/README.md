Problem Description:

	Depth First Traverse:

	Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array. 

Problem Solution:

	With a visited array, we could recursively traverse down the graph from a given vertice from the graph. However, not all vertices are reachable a given vertice, for example, disconnect graph, there are variations to DFT.