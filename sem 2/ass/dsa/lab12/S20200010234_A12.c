#include <stdio.h>
#include <stdlib.h>
#define V 11
#define SIZE 40
int dfsvisited[11] = {0};
int adjMatrix[V][V];

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct node
{
    int vertex;
    struct node *next;
};
struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct queue
{
    int items[SIZE];
    int f;
    int r;
};
void init(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}
void addEdge2(int arr[][V], int src, int dest)
{
    arr[src][dest] = 1;
}
void printAdjMatrix2(int arr[][V])
{
    int i, j;

    for (i = 1; i < V; i++)
    {
        for (j = 1; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int j;
    for (j = 1; j <= vertices; j++)
    {
        graph->adjLists[j] = NULL;
        graph->visited[j] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct stack
{
    int data;
    struct stack *next;
};

struct stack *push(struct stack *p, int item)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = item;
    temp->next = p;
    p = temp;

    return p;
}
int pop(struct stack **p)
{
    struct stack *temp = *p;
    struct stack* q = *p;
    q = q->next;
    *p = q;
    int s = temp->data;
    free(temp);
    return s;
}
int isEmpty(struct stack *p)
{
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = -1;
    q->r = -1;
    return q;
}
int isEmpty2(struct queue *q)
{
    if (q->r == -1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q, int value)
{
    if (q->r == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->f == -1)
            q->f = 0;
        q->r++;
        q->items[q->r] = value;
    }
}

int dequeue(struct queue *q)
{
    int item;
    if (isEmpty2(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->f];
        q->f++;
        if (q->f > q->r)
        {
            printf("Resetting queue ");
            q->f = q->r = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q)
{
    int i = q->f;

    if (isEmpty2(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->f; i < q->r + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}
void bfs(struct Graph *graph, int startVertex)
{
    struct queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty2(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
void DFS_Conn(struct Graph *graph, int vertex)
{
    struct stack *top = NULL;
    top = push(top, vertex);
    while (isEmpty(top) == 0)
    {
        int u = pop(&top);
        if (dfsvisited[u] == 0)
            dfsvisited[u] = 1;
        for (int i = 1; i < 11; i++)
        {
            if (adjMatrix[u][i] == 1){
                if(dfsvisited[i] == 0)top = push(top,i);
            }
        }
    }
}

int main()
{

    printf("\nQuestion1:-\n");
    struct Graph *graph = createGraph(11);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 6, 7);

    init(adjMatrix);
    addEdge2(adjMatrix, 1, 2);
    addEdge2(adjMatrix, 2, 3);
    addEdge2(adjMatrix, 1, 3);
    addEdge2(adjMatrix, 2, 4);
    addEdge2(adjMatrix, 2, 5);
    addEdge2(adjMatrix, 4, 5);
    addEdge2(adjMatrix, 4, 8);
    addEdge2(adjMatrix, 4, 9);
    addEdge2(adjMatrix, 8, 9);
    addEdge2(adjMatrix, 9, 10);
    addEdge2(adjMatrix, 3, 6);
    addEdge2(adjMatrix, 3, 7);
    addEdge2(adjMatrix, 6, 7);

    printAdjMatrix2(adjMatrix);
    printf("\nSpace complexity is:- O(v^2)\n");
    printf("\nSpace complexity is:- O(v^2)\n");
    //2nd Question
    printf("\nQuestion2:-\n");
    
    bfs(graph,1);
    printf("\nTime complexity is:- O(v+e)\n");
    printf("\nSpace complexity is:- O(v+e)\n");
    //3rd Question 
    printf("\nQuestion3:-\n");
    int p = 0;
    DFS_Conn(graph, 1);
    for (int i = 1; i <= 10; i++)
    {
        if (!dfsvisited[i])
        {
            printf("Graph is not connected\n");
            p = 1;
            break;
        }
    }
    if (!p)
        printf("Graph is Connected\n");
    printf("\nSpace complexity is:- O(v^2)\n");
    printf("\nSpace complexity is:- O(v^2)\n");
    return 0;
}