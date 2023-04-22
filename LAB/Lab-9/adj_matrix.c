// WAP to create an undirected graph using the adjacency matrix method.
#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int main()
{
    int max_edge, i, j, origin, destin;
    int graph_type;
    printf("Enter 1 for undirected graph or 2 for directed graph : ");
    scanf("%d", &graph_type);
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    if (graph_type == 1){
        max_edge = n * (n - 1) / 2;
        // printf("%d",max_edge);
    }
    else
        max_edge = n * (n - 1);
    for (i = 1; i <= max_edge; i++)
    {
        printf("Enter edge %d(-1 -1 to quit) : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n ||origin<0 || destin<0)
            {
                printf("Invalid vertex!\n");
                i--;
            }
        else
        {
            adj[origin][destin] = 1;
            if (graph_type == 1) /*if undirected graph*/
                adj[destin][origin] = 1;
        }
    } /*End of for*/
    printf("The adjacency matrix is : \n");
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}