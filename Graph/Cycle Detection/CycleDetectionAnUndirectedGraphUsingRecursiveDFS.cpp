#include<bits/stdc++.h>
using namespace std;
// Class for an Directed graph
class Graph
{
	private:
		int V;    // No. of vertices
    		list<int> *adj;    // Pointer to an array containing adjacency lists
    		bool is_cyclic_util(int v, bool visited[], int parent);
	public:
    		Graph(int V);   // Constructor
    		void add_edge(int v, int w);   // to add an edge to graph
   	 	bool is_cyclic();   // returns true if there is a cycle
};
 
Graph::Graph(int V)
{
	this->V = V;
    	adj = new list<int>[V];
}
 
void Graph::add_edge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	//make it directed graph
}
 
// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::is_cyclic_util(int v, bool visited[], int parent)
{
    	// Mark the current node as visited
    	visited[v] = true;
    	// Recur for all the vertices adjacent to this vertex
    	list<int>::iterator it;
    	for (it = adj[v].begin(); it != adj[v].end();it++)
    	{
        	// If an adjacent is not visited, then recur for that adjacent
        	if (!visited[*it])
        	{
			//if the adjacent is not visited, but visiting it would eventually lead to find a cycle
           		if (is_cyclic_util(*it, visited, v))
              		{
				return true;
        		}
		} 
        	// If an adjacent is visited and not parent of current vertex,
        	// then there is a cycle.
        	else if (*it != parent)
           	{
			return true;
		}
   	}
    	return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::is_cyclic()
{
    	// Mark all the vertices as not visited and not part of recursion stack
    	bool *visited = new bool[V];
    	for (int i = 0; i < V; i++)
        {
		visited[i] = false;
 	}
       // Call the recursive helper function to detect cycle in different DFS trees
	//it is necessary when graph is not strongly connected
	//since, there is not any mention of the graph being strongly connected, we must do that
    	for (int u = 0; u < V; u++)
        {
		if (!visited[u]) // Don't recur for u if it is already visited
          	{
			//initially for every disjoint n ary tree or for every disjoint component of a graph, the parent is set as -1
			if (is_cyclic_util(u, visited, -1))
             		{
				return true;
 			}
    		
		}	
	}
	//if graph is strongly connected, we can skip that
	return false;
}
 
// Driver program to test above functions
int main()
{
	Graph g(4);
    	g.add_edge(0, 1);
    	g.add_edge(0, 2);
    	g.add_edge(1, 2);
   	g.add_edge(2, 0);
    	g.add_edge(2, 3);
    	g.add_edge(3, 3);
	if(g.is_cyclic())
        	cout << "Graph contains cycle";
    	else
        	cout << "Graph doesn't contain cycle";
    	return 0;
}
