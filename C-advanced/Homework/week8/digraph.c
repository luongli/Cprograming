#include "digraph.h"


Graph createGraph()
{
	Graph g;
	g.edges = make_jrb();
	g.vertices = make_jrb();
	return g;
}


/* insert an edge to directed graph*/
void insertEdge(Graph g, int v1, int v2, double w)
{
	JRB edges = g.edges;
	JRB adj_list = make_jrb();
	Jval data;

	if(w < 0)
		printf("WARNING: weight < 0\n");

	/* find if v1 is alreadly in jrb */
	JRB found = jrb_find_int(edges, v1);

	if(found == NULL){
		/* if v1 is not in graph */
		/* create node v1: key is v1, data is adjacent list */

		/* create adj list of v1*/
		jrb_insert_int(adj_list, v2, jd(w));
		/* add adj_list to data */
		data = new_jval_v(adj_list);

		/* add node v1 to graph */
		jrb_insert_int(edges, v1, data);
	}else{
		/* if v1 is already in graph
		then determine if v2 is in adj_list of v1 */
		adj_list = (JRB) jval_v(found->val);
		found = jrb_find_int(adj_list, v2);

		if(found == NULL){
			// if not found v2
			// insert v2 into adjlist of v1
			jrb_insert_int(adj_list, v2, jd(w));
		}//end nested-if

	}// end else
} //end insertEdge


Jval jv(char *s)
{
	// init struct
	char *sm = (char*) malloc(strlen(s));
	strcpy(sm, s);
	attrb a = (attrb) malloc(sizeof(attrb));
	a->name = sm;
	a->ind = 0;
	a->d = DBL_MAX;
	//add to jval
	Jval val = new_jval_v(a);
	return val;
}

attrb getattrb(JRB node)
{
	return ((attrb) jval_v(node->val));
}

/* insert new node to graph, if the node is already exist,
change its data */
void addVertex(Graph g, int id, char *name)
{
	JRB vertices = g.vertices;
	JRB found;

	// check if node id is in graph
	found = jrb_find_int(vertices, id);

	if(found == NULL){
		// if not found, insert vertex id to graph
		jrb_insert_int(vertices, id, jv(name));
	}else{
		// if found, change the data of node id
		attrb a = getattrb(found);
		if(strcmp(a->name, name)){
			free(a->name);
			found->val = jv(name);
		}
	}

}


/* return the number of incoming edges,
return its incoming nodes at output */
int inDegree(Graph g, int id, int* output)
{
	JRB node;
	JRB found;
	int count = 0;

	jrb_traverse(node, g.edges){
		found = jrb_find_int((JRB) jval_v(node->val), id);
		if(found != NULL){
			output[count] = jval_i(node->key);
			count++;
		} // end if
	}// end traverse

	return count;
} //end inDegree


/* return the number of out going nodes
its out going nodes are returned at output */
int outDegree(Graph g, int id, int* output)
{
	JRB found;
	JRB tmp;
	JRB edges = g.edges;
	JRB adjlist;
	int count = 0;

	found = jrb_find_int(edges, id);

	if(found != NULL){
		adjlist = (JRB)jval_v(found->val);
		jrb_traverse(tmp, adjlist){
			output[count] = jval_i(tmp->key);
			count++;
		} // end traverse
	} // end if

	return count;
} // end outDegree


/* return the name of a vertex */
char *getVertex(Graph g, int id)
{
	JRB found;
	JRB vertices = g.vertices;

	found = jrb_find_int(vertices, id);

	if(found != NULL){
		attrb a = getattrb(found);
		return a->name;
	}else{
		return NULL;
	}
}


/* deallocate memory and remove graph */
void dropGraph(Graph g)
{
	JRB vertices = g.vertices;
	JRB tmp;
	attrb a;

	jrb_traverse(tmp, vertices){
		a = getattrb(tmp);
		free(a->name);
		free(a);
	}
}


/*
void addNode(Graph  g, int v1, int v2, char* name1, char* name2)
{
	insertEdge(g, v1, v2);
	addVertex(g, v1, name1);
	addVertex(g, v2, name2);
}
*/


int hasEdge(Graph g, int v1, int v2)
{
	JRB edges = g.edges;
	JRB adjlist;
	JRB found;

	found = jrb_find_int(edges, v1);
	if(found){
		adjlist = (JRB) jval_v(found->val);
		found = jrb_find_int(adjlist, v2);
		if(found)
			return 1;
		else return 0;
	}else
		return 0;
}


int dequeue(Dllist queue)
{
	Dllist first = dll_first(queue);
	int v = jval_i(first->val);
	dll_delete_node(first);
	return v;
}


void tsort(Graph g)
{
	Dllist queue = new_dllist();
	JRB edges = g.edges;
	JRB vertices = g.vertices;
	JRB tmp;
	int output[100];
	int num;
	int i;
	int ind;
	int id;
	attrb a;

	jrb_rtraverse(tmp, vertices){
		id = jval_i(tmp->key);
		a = getattrb(tmp);
		ind = inDegree(g, id, output);
		a->ind = ind;
		if(ind == 0){
			enqueue(queue, id);
		}
	}

	while(!dll_empty(queue)){
		id = dequeue(queue);
		printf("%s\n", getVertex(g, id));// thay bang function pointer
		num = outDegree(g, id, output);
		for(i = 0; i < num; i++){
			tmp = jrb_find_int(vertices, output[i]);
			a = getattrb(tmp);
			a->ind -= 1;
			if(a->ind == 0) enqueue(queue, output[i]);
		}
	}
}


JRB getAdjList(Graph g, int v)
{
	JRB found = jrb_find_int(g.edges, v);

	if(found){
		return (JRB) jval_v(found->val);
	}else
		return NULL;
}


double getWeight(Graph g, int v1, int v2)
{
	JRB found;
	JRB adjlist = getAdjList(g, v1);

	if(adjlist){
		found = jrb_find_int(adjlist, v2);
		if(found)
			return jval_d(found->val);
		else
			return DBL_MAX;
	}else{
		return DBL_MAX;
	}

}


/* return the node of g.vertices containing id
null if not found
*/
JRB getVertexNode(Graph g, int id)
{
	JRB vertices = g.vertices;
	JRB found = jrb_find_int(vertices, id);

	if(found){
		return found;
	}else{
		return NULL;
	}
}


/* init graph for djistra algorithm */
void initSingleSource(Graph g, int s)
{
	JRB vertices = g.vertices;
	JRB v;
	attrb a;

	jrb_traverse(v, vertices){
		a = getattrb(v);
		a->d = DBL_MAX;
		a->predecessor = NULL;
	}

	v = getVertexNode(g, s);
	if(v){
		a = getattrb(v);
		a->d = 0;
	}else{
		printf("ERROR: node %d does not exist\n", s);
		exit(1);
	}
}


void relax(Graph g, int u, int v)
{
	JRB node_u = getVertexNode(g, u);
	JRB node_v = getVertexNode(g, v);

	if(!node_u){
		printf("In relax function, node_u == NULL\n");
		exit(1);
	}

	if(!node_v){
		printf("In relax function, node_v == NULL\n");
		exit(1);
	}

	attrb attrb_u = getattrb(node_u);
	attrb attrb_v = getattrb(node_v);
	double w = getWeight(g, u, v);

	if(attrb_v->d > attrb_u->d + w){
		attrb_v->d = attrb_u->d + w;
		attrb_v->predecessor = node_u;
	}

}


int getAdjVertices(Graph g, int id, int* output)
{
	JRB tmp;
	int i;
	JRB adjlist = getAdjList(g, id);
	if(!adjlist){
		return -1;
	}
	jrb_traverse(tmp, adjlist){
		output[i] = jval_i(tmp->key);
		i++;
	}

	return i;
}


int extractMin(Graph g, Dllist Q)
{
	int min = INT_MAX;
	Dllist min_node;
	JRB v;
	int id;
	Dllist tmp;
	attrb a;

	dll_traverse(tmp, Q){
		v = getVertexNode(g, jval_i(tmp->val));
		a = getattrb(v);
		if(min > a->d){
			min = a->d;
			min_node = tmp;
		}
	}

	id = jval_i(min_node->val);
	dll_delete_node(min_node);

	return id;
}


double shortestPath(Graph g, int s, int d, int *path, int *len)
{
	int i = 0;
	int j, pre;
	int u;
	int n;
	int adj_vertices[100];
	double w = 0;
	JRB tmp;
	Dllist Q = new_dllist();
	initSingleSource(g, s);
	// add vertices to queue
	jrb_traverse(tmp, g.vertices){
		dll_append(Q, tmp->key);
	}

	pre = s;

	while(!dll_empty(Q)){
		u = extractMin(g, Q);
		if(u != pre){
			w += getWeight(g, pre, u);
		}
		pre = u;

		path[i] = u;
		i++;
		if(u == d){
			// reach the destination
			*len = i;
			return w;
		}
		n = getAdjVertices(g, u, adj_vertices);
		for(j = 0; j < n; j++){
			relax(g, u, adj_vertices[j]);
		}
	}

	return DBL_MAX;
}