#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "jrb.h"
#include "dllist.h"


#define DBL_MAX LONG_MAX
#define ji(i) new_jval_i(i)
#define jd(d) new_jval_d(d)
#define enqueue(queue, id) dll_append(queue, new_jval_i(id))

typedef struct{
	char *name;
	int ind;
	double d;
} at;

typedef at* attrb;


typedef struct{
	JRB edges;
	JRB vertices;
} Graph;

Graph createGraph();
void addVertex(Graph, int, char *);
void insertEdge(Graph, int, int, double);
int inDegree(Graph, int, int*);
int outDegree(Graph, int, int*);
char *getVertex(Graph, int);
int hasEdge(Graph, int, int);
void dropGraph(Graph);
void tsort(Graph);
attrb getattrb(JRB);
double getWeight(Graph, int, int);

//void addNode(Graph, int, int, char*, char*);
//int getComponents(Graph);