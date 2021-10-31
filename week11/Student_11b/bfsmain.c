#include<stdio.h>
#include "bfs.h"

int main()
{
    int n, q, u, v;
    printf("Enter the number of nodes and Number of queries : ");
    scanf("%d %d", &n, &q);
    int **graph = (int **)malloc(sizeof(int *) * n);
    printf("Enter the adj matrix : ");
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < q; i++)
    {
        printf("Enter 2 nodes to be checked : ");
        scanf("%d %d", &u, &v);
        if (check_path(graph, n, u - 1, v - 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    return 0;
}


