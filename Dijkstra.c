#include <stdio.h>
#include <stdlib.h>

void dijkstra(int graph[10][10],int V){
    int distance[V], predefine[V], visited[V];
    int startnode, count, min_distance, nextnode, i, j;
    printf("\nEnter the start node: ");
    scanf("%d", &startnode);
    for(i=0; i<V; i++) {
        distance[i] = graph[startnode][i];
        predefine[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while(count<V-1) {
        min_distance = 99;
        for(i=0; i<V; i++) {
            if(distance[i] < min_distance && visited[i]==0) {
                min_distance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for(i=0;i<V;i++) {
            if(visited[i] == 0) {
                if((min_distance + graph[nextnode][i]) < distance[i]) {
                    distance[i] = min_distance + graph[nextnode][i];
                    predefine[i] = nextnode;
                }
            }
        }
        count = count + 1;
    }
    
    for(i=0;i<V;i++) {
        if(i!=startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d",i);
            j = i;
            do {
                j = predefine[j];
                printf(" <- %d",j);
            } while (j != startnode);
        }
    }
    
}

int main(){
    int i, j;
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("\nEnter the cost/weight matrix: \n");
    for(i=0; i<V; i++) {
        for(j=0;j<V;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    dijkstra(graph, V);
    return 0;
}
