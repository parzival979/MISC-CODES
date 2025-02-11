/* Question 2 : Take a complete graph of N nodes. N should be input from the user. Store it using either
Adjecency Matrix or Adjecency List. Edge weights (>0, integer) can be taken as random. Find
out the Minimum spannging tree using Prim's and Kruskal Algorithm.
This code has been written by CS20B1006 SRAVANTH CHOWDARY POTLURI*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

// A structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};

// A structure to represent a connected, undirected and weighted graph with a edge node and adjacent weight matrix
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    //Graph is represented as an array of edges.
    //Since the graph is undirected, the edge from src to dest is also edge from dest to src.
    struct Edge* edge;
    int **weights;
};

// Creates a Complete graph with V vertices and (V*V-1)/2 edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(sizeof(struct Edge)*E);
    graph->weights = malloc(V * sizeof(int *));
    for (int i = 0; i < V; ++i)
        graph->weights[i] = malloc(V * sizeof(int));
    for(int u = 0; u < V; ++u){
        for(int v = 0; v < V; ++v){
            graph->weights[u][v] = 0;
        }
    }
    srand(time(NULL));
    int e = 0;
    printf("The Given Graph is :");
    printf("\nEdge \tWeight\n");
    for (int i = 0; i < graph->V - 1 && e < graph->E; i++){
        for (int j = i + 1; j < graph->V; j++){
            graph->edge[e].src = i;
            graph->edge[e].dest = j;
            graph->edge[e].weight = rand()%10 + 1;
            graph->weights[i][j] = graph->edge[e].weight;
            graph->weights[j][i] = graph->edge[e].weight;
            printf("%d -- %d == %d\n", graph->edge[e].src, graph->edge[e].dest, graph->edge[e].weight);
            ++e;
        }
    }
    return graph;
}

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], struct Graph *graph){
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < graph->V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], struct Graph * graph){
    printf("Following are the edges in the constructed MST using Prim's algorithm :");
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < graph->V; i++)
        printf("%d -- %d \t  %d \n", parent[i], i, graph->weights[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(struct Graph * graph){
    // Array to store constructed MST
    int parent[graph->V];
    // Key values used to pick minimum weight edge in cut
    int key[graph->V];
    // To represent set of vertices included in MST
    int mstSet[graph->V];
    // Initialize all keys as INFINITE
    for (int i = 0; i < graph->V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    //Always include first 1st vertex in MST. Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
    // The MST will have V vertices
    for (int count = 0; count < graph->V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, graph);
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < graph->V; v++)
            /* graph[u][v] is non zero only for adjacent vertices of m. mstSet[v] is false for vertices not yet included
             in MST. Update the key only if graph[u][v] is smaller than key[v] */
            if (graph->weights[u][v] && mstSet[v] == 0 && graph->weights[u][v] < key[v])
                parent[v] = u, key[v] = graph->weights[u][v];
    }
    // print the constructed MST
    printMST(parent, graph);
}

// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

// A utility function to find set of an element i
int find(struct subset subsets[], int i){
    //Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
void Union(struct subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

        //If ranks are same, then make one as root and increment its rank by one
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights. Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph){
    int V = graph->V;
    struct Edge result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges
    /*Sort all the edges in non-decreasing order of their weight. If we are not allowed to change the given graph,
    we can create a copy of array of edges */
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
    // Allocate memory for creating V ssubsets
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        //Pick the smallest edge. And increment the index for next iteration
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        //If including this edge does't cause cycle,include it in result and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST using Kruskal's algorithm :");
    int minimumCost = 0;
    printf("\nEdge \tWeight\n");
    for (i = 0; i < e; ++i){
        printf("%d -- %d\t  %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning tree : %d",minimumCost);
    return;
}

void deletegraph(struct Graph* graph){
    for (int i = 0; i < graph->V; i++)
        free(graph->weights[i]);
    free(graph->edge);
    free(graph->weights);
    free(graph);
}

int main(){
    int V;
    printf("Enter the number of nodes of the Complete graph you want to create\n");
    scanf("%d",&V);
    int E = (V*(V-1))/2;
    struct Graph* graph = createGraph(V, E);
    primMST(graph);
    KruskalMST(graph);
    deletegraph(graph);
}