#include<bits/stdc++.h>
using namespace std;
// This class represents a directed graph using
// adjacency list representation
class Graph
{
	private:
		int V;
		// No. of vertices
    		// Pointer to an array containing adjacency
    		// lists
    		list<int> *adj;   
	public:
    		Graph(int V);
		// Constructor
    		// function to add an edge to graph
    		void add_edge(int v, int w); 
 		// prints BFS traversal from a given source s
    		void BFS(int s);  
};
 
Graph::Graph(int V)
{
    	this->V = V;
	adj=NULL;
	try
	{
    		adj = new list<int>[V];
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for adj list array for V number of vertices\n";
	}
	
}
 
void Graph::add_edge(int v, int w)
{
	//a directed graph
    	adj[v].push_back(w);
	// Add w to v’s list.
}
 
void Graph::BFS(int s)
{
	//source node: the node from which we want to start, is user choice
    	// Mark all the vertices as not visited
    	bool *visited = new bool[V];
    	for(int i = 0; i < V; i++)
        {
		visited[i] = false;
 	}
    	// Create a queue for BFS
    	queue<int> temp_queue;
 	// Mark the current node as visited and enqueue it
    	visited[s] = true;
    	temp_queue.push(s);
 	// 'i' will be used to get all adjacent
    	// vertices of a vertex
    	list<int>::iterator it;
    	while(!temp_queue.empty())
    	{
        	// Dequeue a vertex from queue and print it
        	s=temp_queue.front();
        	cout << s << " ";
       	 	temp_queue.pop();
       	 	// Get all adjacent vertices of the dequeued
        	// vertex s. If a adjacent has not been visited, 
        	// then mark it visited and enqueue it
        	for (it = adj[s].begin(); it != adj[s].end(); it++)
        	{
            		if (!visited[*it])
            		{
                		visited[*it] = true;
                		temp_queue.push(*it);
			}
        	}
    	}
}
// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	try
	{
    		Graph g(4);
    		g.add_edge(0, 1);
    		g.add_edge(0, 2);
    		g.add_edge(1, 2);
    		g.add_edge(2, 0);
    		g.add_edge(2, 3);
    		g.add_edge(3, 3);
    		cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    		g.BFS(2);
	}
	catch(const char* e)
	{
		printf("The exception thrown: %s\n",e);
	}
 	return 0;
}

