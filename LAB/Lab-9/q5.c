#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void init(int **arr, int V)
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}
void addEdge(int **arr, int i, int j, int V)
{
    (arr[i])[j] = 1;
    (arr[j])[i] = 1;
}
bool isCycle(int **graph,int u, bool visited[], int parent, int V)
{
    visited[u] = true; // mark v as visited
    for (int v = 0; v < V; v++)
    {
        if (((graph)[u])[v])
        {
            if (!visited[v])
            {
                if (isCycle(graph, v, visited, u, V))
                {
                    return true;
                }
            }
            else if (v != parent)
            {               
                return true;
             }
        }
    }
    return false;
}
bool isTree(int **graph, int V)
{
    bool *vis = malloc(sizeof(bool) * V);
    for (int i = 0; i < V; i++)
        vis[i] = false; // initialize as no node is visited
    if (isCycle(graph, 0, vis, -1, V)) // check if there is a cycle or not
        return false;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i]) 
            return false;
    }
    return true;
}
int main()
{
    int V;
    int inp1, inp2;
    int c = 1;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int **graph = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
    {
        graph[i] = malloc(sizeof(int) * V);
    }
    init(graph, V);
    while (c)
    {
        printf("Enter the edge (-1 for exit): ");
        scanf("%d", &inp1);
        if (inp1 == -1)
            break;
        scanf("%d", &inp2);
        addEdge(graph, inp1, inp2, V);
    }
    bool isTrue = isTree(graph, V);
    if (isTrue)
        printf("The graph is a tree.\n");
    else
        printf("The graph is not tree.\n");
    return 0;
}
