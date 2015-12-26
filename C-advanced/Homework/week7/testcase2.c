#include "adjgraph.h"

int main()
{
	Graph g = createGraph();
	int i, num;
	int adjlist[100]={0};

	addEdgeI(g, 1, 2);
	addEdgeI(g, 1, 3);
	addEdgeI(g, 1, 4);
	addEdgeI(g, 2, 1);
	addEdgeI(g, 2, 3);
	addEdgeI(g, 2, 4);
	addEdgeI(g, 3, 4);
	addEdgeI(g, 2, 1);
	addEdgeI(g, 3, 1);

	printf("Breath first search\n");
	BFS(g, 1, &printI);

	printf("Depth first search\n");
	DFS(g, 1, &printI);

}
