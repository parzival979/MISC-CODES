/* Question 1 : Take a random connected directed acyclic graph. Store it using Adjacency Matrix as well as
Adjacency list. Implement the Breadth-first search, Depth-first search and Topological sort
using both the storage structures.
This code has been written by CS20B1006 SRAVANTH CHOWDARY POTLURI*/

#include<stdio.h>
#include<stdlib.h>

// A structure to represent an adjacency list node and for the queue in BFS and DFS and Topological sort
struct Node{
    int data;
    struct Node *next;
};

// A structure to represent an adjacency list
struct AdjList{
    struct Node *head;
};

// A structure for queue used in BFS
struct Queue{
    struct Node *front;
    struct Node *rear;
};

// Queue related functions
void Enqueue(struct Queue *q, int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (q->rear == NULL){
        q->rear = q->front = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

int Dequeue(struct Queue *q){
    int data;
    if (q->front ==  NULL)
        return -1;
    struct Node *temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void DeleteQueue(struct Queue *q){
    struct Node *temp;
    while(q->front != NULL){
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

/* A structure to represent graph which has number of vertices,an adjacency list array,adj matrix, vsited array and
indegree array to store adjacent vertices of the vertex */
struct Graph{
    int V;
    struct AdjList* array;
    int **adj_matrix;
    int *visited;
    int *indegree1;
    int *indegree2;
};

struct Node* newAdjListNode(int dest){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    graph->adj_matrix = malloc(V * sizeof(int *));
    graph->visited = malloc(V * sizeof(int));
    graph->indegree1 = malloc(V * sizeof(int));
    graph->indegree2 = malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        graph->adj_matrix[i] = malloc(V * sizeof(int));
    // For Adjacency List and visited array
    for (int i = 0; i < V; ++i){
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
        graph->indegree1[i] = 0;
        graph->indegree2[i] = 0;
    }
    // For Adjacency Matrix
    for(int u = 0; u < V; ++u){
        for(int v = 0; v < V; ++v){
            graph->adj_matrix[u][v] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    // Adding only one edge from src to dest as it's directed
    // For Adjacency list
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    // For Adjacency Matrix
    graph->adj_matrix[src][dest] = 1;
    graph->indegree1[dest] += 1;
    graph->indegree2[dest] += 1;
}

void printAdjlist(struct Graph* graph){
    printf("Adjacency list of the given graph is : \n");
    for (int v = 0; v < graph->V; ++v){
        struct Node* pCrawl = graph->array[v].head;
        printf("Adjacency list of vertex %d : ", v);
        while (pCrawl){
            printf(" %d ", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void printAdjmatrix(struct Graph* graph){
    printf("Adjacency matrix of the given graph :\n");
    for(int u = 0; u < graph->V; ++u){
        for(int v = 0; v < graph->V; ++v){
            printf(" %d ",graph->adj_matrix[u][v]);
        }
        printf("\n");
    }
}

void BFS_matrix(struct Graph* graph,int s){
    int V = graph->V;
    // Initializing the visited array of all vertices to be not visited
    for(int i = 0; i < V; i++)
        graph->visited[i] = 0;
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    Enqueue(q,s);
    while (q->front != NULL){
        s = Dequeue(q);
        printf(" %d ",s);
        graph->visited[s] = 1;
        for (int i = 0; i < V; i++){
            if (graph->visited[i] == 0 && graph->adj_matrix[s][i] == 1){
                graph->visited[i] = 1;
                Enqueue(q,i);
            }
        }
    }
    printf("\n");
    DeleteQueue(q);
}

void BFS_list(struct Graph* graph, int s){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    int V = graph->V;
    for(int i = 0; i < V; i++)
        graph->visited[i] = 0;
    graph->visited[s] = 1;
    Enqueue(q,s);
    //printf("Nodes Visited :\n");
    while (q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ",u);
        struct Node* pCrawl = graph->array[u].head;
        while (pCrawl){
            if (graph->visited[pCrawl->data] == 0){
                graph->visited[pCrawl->data] = 1;
                Enqueue(q,pCrawl->data);
            }
            pCrawl = pCrawl->next;
        }
    }
    printf("\n");
    DeleteQueue(q);
}

void DFS_matrix(struct Graph* graph,int s){
    int V = graph->V;
    graph->visited[s] = 1;
    printf(" %d ", s);
    for (int i = 0; i < V; i++){
        if(graph->visited[i] == 0 && graph->adj_matrix[s][i] == 1)
            DFS_matrix(graph,i);
    }
}

void DFS_list(struct Graph* graph, int s){
    int V = graph->V;
    struct Node* pCrawl = graph->array[s].head;
    graph->visited[s] = 1;
    printf(" %d ", s);
    while (pCrawl){
        int u = pCrawl->data;
        if (graph->visited[u] == 0)
            DFS_list(graph,u);
        pCrawl = pCrawl->next;
    }
}

void initialize(struct Graph* graph){
    for(int i = 0; i < graph->V; i++){
        graph->visited[i] = 0;
    }
}

void Topology_sort_matrix(struct Graph* graph){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    int counter = 0;
    int topologicalorder[graph->V];
    for (int i = 0; i < graph->V; i++){
        if(graph->indegree1[i] == 0)
            Enqueue(q,i);
    }
    while(q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ", u);
        topologicalorder[u] = ++counter;
        for (int i = 0; i < graph->V; i++){
            if (graph->adj_matrix[u][i] == 1 && --graph->indegree1[i] == 0)
                Enqueue(q,i);
        }
    }
    printf("\n");
    DeleteQueue(q);
    if (counter != graph->V)
        printf("Graph has a cycle so topology sort not possible\n");
}

void Topology_sort_list(struct Graph* graph){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    int counter = 0;
    int topologicalorder[graph->V];
    for (int i = 0; i < graph->V; i++){
        if(graph->indegree2[i] == 0)
            Enqueue(q,i);
    }
    while(q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ", u);
        topologicalorder[u] = ++counter;
        struct Node* pCrawl = graph->array[u].head;
        while (pCrawl){
            if (--graph->indegree2[pCrawl->data] == 0)
                Enqueue(q,pCrawl->data);
            pCrawl = pCrawl->next;
        }
    }
    printf("\n");
    DeleteQueue(q);
    if (counter != graph->V)
        printf("Graph has a cycle so topology sort not possible\n");
}

void deletegraph(struct Graph* graph){
    for (int i = 0; i < graph->V; i++) {
        free(graph->array[i].head);
    }
    for (int i = 0; i < graph->V; i++)
        free(graph->adj_matrix[i]);
    free(graph->adj_matrix);
    free(graph->visited);
    free(graph->indegree1);
    free(graph->indegree2);
    free(graph);
}

int main(){
    int V = 7;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 6, 5);
    printAdjlist(graph);
    printAdjmatrix(graph);
    printf("The BFS traversal using adjacency matrix from vertex 0 is \n");
    BFS_matrix(graph,0);
    printf("The BFS traversal using adjacency list from vertex 0 is \n");
    BFS_list(graph,0);
    initialize(graph);
    printf("The DFS traversal using adjacency matrix from vertex 0 is \n");
    DFS_matrix(graph,0);
    initialize(graph);
    printf("\nThe DFS traversal using adjacency list from vertex 0 is \n");
    DFS_list(graph,0);
    printf("\n");
    printf("The Topological sort of the given graph using adjacency matrix : \n");
    Topology_sort_matrix(graph);
    printf("The Topological sort of the given graph using adjacency list : \n");
    Topology_sort_list(graph);
    deletegraph(graph);
}