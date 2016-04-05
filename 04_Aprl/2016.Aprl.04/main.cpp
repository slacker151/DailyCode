#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <list>

class Graph
{
public:
	Graph(int);
	~Graph();
	void addEdge(int v, int w);
	void BFS(int s);
private:
	int V;
	std::list<int> *adj;
};

Graph::Graph(int NumOfVertices)
	: V(0)
	, adj(NULL)
{
	this->V = NumOfVertices;
	adj = new std::list<int>[NumOfVertices];
}

Graph::~Graph()
{
	if(adj != NULL)
	{
		delete [] adj;
	}
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int start)
{
	bool *visited = new bool[V];
	std::fill_n(visited, V, false);

	std::list<int> queue;

	visited[start] = true;
	queue.push_back(start);

	while(!queue.empty())
	{
		int temp = queue.front();
		std::cout << std::setw(4) << temp;
		queue.pop_front();

		std::list<int>::iterator it;

		for (it = adj[temp].begin(); it != adj[temp].end(); ++it)
		{
			if(!visited[*it])
			{
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	Graph G(4);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	std::cout << "Following is BFT (starting from vertex 2): \n"; 

	G.BFS(2);

	return 0;
}