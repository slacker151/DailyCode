Problem Description:

	Dijkstra's Shortest Path Algorithm

	Given a graph and a source vertex in that graph, find the
	shortest path from source to all vertices in the graiven graph.

Problem Solution:

	Below are the detailed steps used in Dijkstra'a algorithm to 
	find the shortest path from a single source vertex to all 
	other vertices in the given graph:

	1. Create a set sptSet(shortest path tree set) that keeps track fo vertices included in shorest path tree, i.e. whose minimum distance frmo sources is calculated and finalized. Initially, this set is empty.

	2. Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance values as 0 for the source vertex so that it is picked first.

	3. While spt Set doesn't include all vertices:
		a. Pick a vertes u which is not in sptSet and has minimum distance value.
		b. Include u in sptSet
		c. Update distance value of all adacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.


	Notes:

		1. Dijkstra's algorithm doesn't work for graphs with negative edges. For graphs with negative weight edges, Bellman-Frod algorithm can be used, we will soon be discussing it as a separate post.


	