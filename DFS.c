#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct node *adj[20];
int visited[20], n, end, found = 0;

struct node* createNode(int v)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

void dfs(int v)
{
    struct node *temp;

    if (found)
        return;

    visited[v] = 1;
    printf("%d ", v);

    if (v == end)
    {
        found = 1;
        return;
    }

    temp = adj[v];
    while (temp != NULL)
    {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

int main()
{
    int i, e, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source and destination edges:\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Enter ending vertex: ");
    scanf("%d", &end);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
